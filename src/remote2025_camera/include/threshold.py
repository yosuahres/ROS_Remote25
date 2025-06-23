import cv2

# Fungsi dummy untuk trackbar
def nothing(x):
    pass

# Inisialisasi kamera
cap = cv2.VideoCapture(0)
if not cap.isOpened():
    raise IOError("Tidak dapat membuka kamera")

# Buat jendela dan trackbar
cv2.namedWindow('Adaptive Threshold')
cv2.createTrackbar('Block Size', 'Adaptive Threshold', 11, 50, nothing)  # Harus ganjil & >=3
cv2.createTrackbar('C', 'Adaptive Threshold', 2, 20, nothing)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    # Resize agar ringan
    frame = cv2.resize(frame, (640, 480))

    # Konversi ke grayscale & blur
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blurred = cv2.GaussianBlur(gray, (5, 5), 0)

    # Ambil nilai dari trackbar
    block_size = cv2.getTrackbarPos('Block Size', 'Adaptive Threshold')
    c = cv2.getTrackbarPos('C', 'Adaptive Threshold') - 10

    # Pastikan block size ganjil dan minimal 3
    if block_size % 2 == 0:
        block_size += 1
    if block_size < 3:
        block_size = 3

    # Adaptive threshold
    adaptive_thresh = cv2.adaptiveThreshold(
        blurred,
        255,
        cv2.ADAPTIVE_THRESH_GAUSSIAN_C,
        cv2.THRESH_BINARY_INV,
        block_size,
        c
    )

    # Tampilkan hasil
    cv2.imshow('Original', frame)
    cv2.imshow('Adaptive Threshold', adaptive_thresh)

    # Tekan Q untuk keluar
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
