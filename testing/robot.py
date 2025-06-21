import requests
import json

# Alamat IPv6 dari server Flask yang menjalankan Reactor
ipv6 = "fc94:0cfb:17c0:b92c:eb2f:4bda:462f:a67e"

# Minta input password dari user
password = input("🔐 Masukkan password: ").strip()

# Bentuk URL endpoint
url = f"http://[{ipv6}]:5000/data.json?password={password}"

try:
    # Kirim GET request ke server
    response = requests.get(url)

    # Jika berhasil, proses response
    if response.status_code == 200:
        # Cetak raw JSON
        print("\n📦 Raw JSON response:")
        print(json.dumps(response.json(), indent=4))

        # Parsing data
        data = response.json()
        print("\n✅ Parsed Output:")
        print("Status       :", data.get('status'))
        print("Access Level :", data.get('access_level'))
        print("Destination  :", data.get('destination'))

        if data.get('access_level') == 'advanced':
            print("Hazards:")
            for h in data.get('hazards', []):
                print(f"  - lat: {h['lat']}, lon: {h['lon']}")
    else:
        print(f"❌ Gagal mengambil data. Status code: {response.status_code}")
except requests.exceptions.RequestException as e:
    print(f"❌ Error saat mencoba koneksi: {e}")