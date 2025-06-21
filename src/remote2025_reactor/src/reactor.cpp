#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/point.hpp"

#include <curl/curl.h>
#include <nlohmann/json.hpp>

#include <fstream>
#include <sstream>
#include <string>
#include <memory>

using json = nlohmann::json;

class ReactorClientNode : public rclcpp::Node {
public:
    ReactorClientNode()
    : Node("reactor_client_node"), last_written_("") {
        ipv6_ = this->declare_parameter("ipv6", "fc94:5497:f336:fab0:aa41:f68a:53f5:8c1c");
        password_ = this->declare_parameter("password", "");
        std::string password_file = this->declare_parameter("password_file", "");

        if (!password_file.empty()) {
            std::ifstream file(password_file);
            if (file) {
                std::getline(file, password_);
                RCLCPP_INFO(this->get_logger(), "🔐 Password loaded from file");
            } else {
                RCLCPP_ERROR(this->get_logger(), "❌ Failed to read password file");
                rclcpp::shutdown();
                return;
            }
        }

        if (password_.empty()) {
            RCLCPP_ERROR(this->get_logger(), "❌ No password provided.");
            rclcpp::shutdown();
            return;
        }

        url_ = "http://[" + ipv6_ + "]:5000/data.json?password=" + password_;

        publisher_ = this->create_publisher<geometry_msgs::msg::Point>("reactor_data", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(3),
                                         std::bind(&ReactorClientNode::fetch_data, this));
    }

private:
    std::string ipv6_, password_, url_;
    std::string last_written_;
    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    void fetch_data() {
        CURL *curl = curl_easy_init();
        if (!curl) {
            RCLCPP_ERROR(this->get_logger(), "❌ Failed to init CURL");
            return;
        }

        std::string response_data;
        curl_easy_setopt(curl, CURLOPT_URL, url_.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_data);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 5L);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            RCLCPP_ERROR(this->get_logger(), "❌ CURL error: %s", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return;
        }

        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        curl_easy_cleanup(curl);

        if (http_code == 200) {
            try {
                auto parsed = json::parse(response_data);
                double lat = parsed["destination"]["lat"];
                double lon = parsed["destination"]["lon"];

                geometry_msgs::msg::Point msg;
                msg.x = lat;
                msg.y = lon;
                msg.z = 0.0;

                publisher_->publish(msg);
                RCLCPP_INFO(this->get_logger(), "📡 Published Point(lat=%.6f, lon=%.6f)", lat, lon);

                std::string content = std::to_string(lat) + "," + std::to_string(lon) + "\n";
                if (content != last_written_) {
                    std::ofstream out_file(std::string(std::getenv("HOME")) + "/reactor_output.txt");
                    out_file << content;
                    last_written_ = content;
                    RCLCPP_INFO(this->get_logger(), "📝 Written to ~/reactor_output.txt");
                }
            } catch (std::exception &e) {
                RCLCPP_ERROR(this->get_logger(), "❌ JSON parsing error: %s", e.what());
            }
        } else {
            RCLCPP_WARN(this->get_logger(), "⚠️ HTTP Status: %ld", http_code);
        }
    }
};

int main(int argc, char * argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ReactorClientNode>());
    rclcpp::shutdown();
    return 0;
}