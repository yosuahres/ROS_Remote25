import subprocess

DEVICE = "/dev/video0"

def set_ctrl(ctrl, value):
    try:
        subprocess.run(["v4l2-ctl", "-d", DEVICE, "--set-ctrl", f"{ctrl}={value}"], check=True)
        print(f"Resetting {ctrl} to {value}")
    except subprocess.CalledProcessError as e:
        print(f"{ctrl}: {e}")

# First: disable automatic modes
set_ctrl("white_balance_automatic", 0)  # disable auto WB
set_ctrl("auto_exposure", 1)            # manual exposure mode
set_ctrl("focus_automatic_continuous", 0)  # disable auto focus

# Then: set manual values
set_ctrl("white_balance_temperature", 4600)
set_ctrl("exposure_time_absolute", 312)
set_ctrl("focus_absolute", 0)

# Reset others (order not critical)
set_ctrl("brightness", 0)
set_ctrl("contrast", 6)
set_ctrl("saturation", 86)
set_ctrl("hue", 0)
set_ctrl("gamma", 100)
set_ctrl("power_line_frequency", 1)
set_ctrl("sharpness", 2)
set_ctrl("backlight_compensation", 0)
