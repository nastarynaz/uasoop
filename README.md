# Hotel Management System

Program manajemen hotel sederhana yang dibangun menggunakan C++ dengan konsep Object-Oriented Programming (OOP).

## 📋 Deskripsi

Program ini adalah sistem manajemen hotel yang memungkinkan:

- Pengelolaan kamar hotel dengan berbagai tipe (Deluxe, Superior, Suite)
- Manajemen data customer
- Pembuatan dan pembatalan reservasi
- Menampilkan ringkasan hotel

## 📁 Struktur File

```
Tugas_OOP_Hotel/
├── main.cpp           # File utama program
├── Hotel.h            # Header file untuk class Hotel
├── Hotel.cpp          # Implementasi class Hotel
├── Customer.h         # Header file untuk class Customer
├── Customer.cpp       # Implementasi class Customer
├── Room.h             # Header file untuk class Room
├── Room.cpp           # Implementasi class Room
├── Reservation.h      # Header file untuk class Reservation
├── Reservation.cpp    # Implementasi class Reservation
├── Pakta_Integritas.txt
└── README.md          # File dokumentasi ini
```

## 🛠️ Requirements

- **Compiler C++**: g++ (GCC) atau clang++ yang mendukung C++11 atau yang lebih baru
- **Operating System**: Windows, macOS, atau Linux

### Instalasi Compiler (jika belum ada):

**macOS:**

```bash
# Install Xcode Command Line Tools
xcode-select --install
```

**Windows:**

```bash
# Install MinGW-w64 atau gunakan Visual Studio
```

**Linux (Ubuntu/Debian):**

```bash
sudo apt update
sudo apt install g++
```

## 🔧 Cara Compile

```bash
# Compile semua file .cpp sekaligus
g++ -o hotel_program main.cpp Customer.cpp Hotel.cpp Reservation.cpp Room.cpp
```

## 🚀 Cara Menjalankan Program

Setelah berhasil compile, jalankan program dengan perintah:

### Windows:

```bash
hotel_program.exe
```

### macOS/Linux:

```bash
./hotel_program
```

## 📝 Contoh Output Program

Program akan menampilkan output seperti berikut:

```
>>> SKENARIO: PEMESANAN

Reservasi berhasil: ID Reservasi [1] untuk Customer [Budi]
Kamar tidak tersedia! Reservasi gagal untuk Customer [Ani]
Reservasi berhasil: ID Reservasi [2] untuk Customer [Ani]

=== DAFTAR RESERVASI ===
[1] Budi - Deluxe (101): 2025-12-23 to 2025-12-25
[2] Ani - Superior (102): 2025-12-26 to 2025-12-28

>>> SKENARIO: PEMBATALAN
Reservasi ID [1] berhasil dibatalkan.
Ani mencoba memesan kamar yang dibatalkan Budi...
Reservasi berhasil: ID Reservasi [3] untuk Customer [Ani]

=== RINGKASAN HOTEL ===
Hotel: Hotel Gadjah Mada
Alamat: Jl. Grafika No. 2, Yogyakarta
Total Reservasi: 2
```

## 📚 Konsep OOP yang Digunakan

- **Encapsulation**: Data dan method dikapsulkan dalam class
- **Inheritance**: Kemungkinan inheritance pada class Room
- **Polymorphism**: Penggunaan virtual function jika ada
- **Abstraction**: Interface yang jelas untuk setiap class

## 👨‍💻 Pengembangan

Untuk melakukan modifikasi atau pengembangan:

1. Edit file header (.h) untuk menambah deklarasi
2. Edit file implementation (.cpp) untuk menambah implementasi
3. Compile ulang menggunakan salah satu metode di atas
4. Test program untuk memastikan fungsionalitas

## 📄 Lisensi

Program ini dibuat untuk keperluan pembelajaran dan tugas akademik.

---

**Dibuat oleh**: Muhammad Khoirunas
**Tanggal**: 20 Desember 2025  
**Mata Kuliah**: Object-Oriented Programming
