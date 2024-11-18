# Tugas2_CV_URO

### Deskripsi Tugas
Proyek ini bertujuan untuk mendeteksi objek 2D pada video menggunakan teknik pemrosesan gambar dengan OpenCV. Program ini diimplementasikan dalam bahasa **C++** menggunakan **OpenCV** dan **CMake** di lingkungan **Ubuntu** (dual boot).

### Fitur Utama
1. Parsing frame dari video menggunakan `VideoCapture`.
2. Masking video menggunakan ruang warna **HSV** untuk mendeteksi objek berdasarkan warna.
3. Mendeteksi **contours** dari objek yang terdeteksi.
4. Menggambar **bounding rectangle** di sekitar objek yang terdeteksi.
5. Menyaring objek berdasarkan area contour untuk menghindari noise.
6. Dokumentasi video deteksi objek saat program dijalankan.

### Bonus
- Implementasi proyek menggunakan **C++** dengan setup **CMake** dan **Ubuntu (dual-boot)**.

### Super Bonus
- Menggunakan algoritma **YOLO (You Only Look Once)** untuk deteksi objek.

## Cara Menjalankan Program

### Persyaratan
Pastikan Anda sudah menginstal:
- **OpenCV** (minimal versi 4.x)
- **CMake** untuk mengonfigurasi dan membangun proyek C++
- **YOLOv3** model (untuk super bonus)

### Langkah-langkah Build dan Run
1. Clone repository ini:
   ```bash
   git clone https://github.com/Camn0/Tugas2_CV_URO.git
   cd Tugas2_CV_URO
   cd opencyproyek
   ```

2. Build proyek dengan **CMake**:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

3. Jalankan program deteksi objek:
   ```bash
   ./object_detection
   ```

4. Untuk YOLO, navigasi ke folder `yolo_proyek/` dan build proyek:
   ```bash
   cd yolo_proyek
   mkdir build
   cd build
   cmake ..
   make
   ./yolo_detection
   ```

## Dokumentasi Video

### Tugas Wajib
Link video deteksi objek menggunakan OpenCV: https://drive.google.com/file/d/1MCzS70ob8T8hmq9_eUVdrpL13yPe1Tuq/view?usp=drivesdk

### Super Bonus (YOLO)
Link video deteksi objek menggunakan YOLO: https://drive.google.com/file/d/1x8CXj87yCM4mpO-mkRp5-TvBT6MYTRZT/view?usp=sharing
