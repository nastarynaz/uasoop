# 🏨 Hotel Management System

Program manajemen hotel sederhana yang dibangun menggunakan C++ dengan konsep Object-Oriented Programming (OOP).

## 📋 Deskripsi

Program ini adalah sistem manajemen hotel interaktif yang memungkinkan:

- Pengelolaan kamar hotel dengan berbagai tipe (Deluxe, Superior, Suite)
- Manajemen data customer
- Pembuatan dan pembatalan reservasi
- Interface menu yang user-friendly

## 📁 Struktur File

```
Tugas_OOP_Hotel/
├── main.cpp           # File utama program dengan menu interaktif
├── Hotel.h            # Header file untuk class Hotel
├── Hotel.cpp          # Implementasi class Hotel
├── Customer.h         # Header file untuk class Customer
├── Customer.cpp       # Implementasi class Customer
├── Room.h             # Header file untuk class Room dan RoomFactory
├── Room.cpp           # Implementasi class Room
├── Reservation.h      # Header file untuk class Reservation
├── Reservation.cpp    # Implementasi class Reservation
├── Pakta_Integritas.txt
└── README.md          # File dokumentasi ini
```

## 🏗️ Class Diagram

```
┌─────────────────────────────────────────────────────────────┐
│                          Hotel                               │
├─────────────────────────────────────────────────────────────┤
│ - roomList: vector<Room*>                                    │
│ - reservationList: vector<Reservation*>                      │
│ + hotelName: string                                          │
│ + hotelAddress: string                                       │
├─────────────────────────────────────────────────────────────┤
│ + addRoom(Room*)                                             │
│ + showRoomList()                                             │
│ + showReservationList()                                      │
│ + createReservation(Customer*, Room*, string, string)        │
│ + cancelReservationById(int)                                 │
│ + getRoomById(int): Room*                                    │
└─────────────────────────────────────────────────────────────┘

┌─────────────────────────┐     ┌─────────────────────────┐
│        Customer         │     │       Reservation       │
├─────────────────────────┤     ├─────────────────────────┤
│ + idCustomer: int       │     │ + idReservation: int    │
│ + name: string          │     │ + customer: Customer*   │
│ + email: string         │     │ + room: Room*           │
│ + phoneNumber: string   │     │ + checkIn: string       │
├─────────────────────────┤     │ + checkOut: string      │
│ + showCustomerDetails() │     ├─────────────────────────┤
└─────────────────────────┘     │ + showReservationDetails│
                                │ + cancelReservation()   │
                                └─────────────────────────┘

┌─────────────────────────┐
│          Room           │
├─────────────────────────┤
│ + idRoom: int           │
│ + roomType: string      │
│ + price: double         │
│ + status: string        │
│ + capacity: int         │
├─────────────────────────┤
│ + showRoomDetails()     │
│ + changeRoomStatus()    │
└─────────────────────────┘
         ▲
         │ Inheritance
    ┌────┴────┬────────────┐
    │         │            │
┌───┴───┐ ┌───┴───┐ ┌──────┴──────┐
│Deluxe │ │Superior│ │    Suite    │
│ Room  │ │ Room   │ │    Room     │
└───────┘ └────────┘ └─────────────┘
```

## 🛠️ Requirements

- **Compiler C++**: g++ (GCC) atau clang++
- **Operating System**: Windows, macOS, atau Linux

### Instalasi Compiler (jika belum ada):

**macOS:**

```bash
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
g++ -o hotel_program main.cpp Customer.cpp Hotel.cpp Reservation.cpp Room.cpp
```

## 🚀 Cara Menjalankan Program

### Windows:

```bash
hotel_program.exe
```

### macOS/Linux:

```bash
./hotel_program
```

## 📱 Fitur Menu Interaktif

```
========================================
       SISTEM RESERVASI HOTEL UGM
========================================
[1] Tambah Kamar Baru
[2] Lihat Daftar Kamar
[3] Tambah Customer Baru
[4] Lihat Daftar Customer
[5] Buat Reservasi
[6] Lihat Daftar Reservasi
[7] Batalkan Reservasi
[0] Keluar
========================================
```

### Detail Fitur:

| No  | Fitur              | Deskripsi                                                                 |
| --- | ------------------ | ------------------------------------------------------------------------- |
| 1   | Tambah Kamar       | Menambah kamar baru dengan ID otomatis. Pilih tipe: Deluxe/Superior/Suite |
| 2   | Lihat Kamar        | Menampilkan semua kamar beserta status (Available/Booked)                 |
| 3   | Tambah Customer    | Mendaftarkan customer baru dengan ID otomatis                             |
| 4   | Lihat Customer     | Menampilkan daftar customer terdaftar                                     |
| 5   | Buat Reservasi     | Membuat reservasi dengan memilih customer dan kamar                       |
| 6   | Lihat Reservasi    | Menampilkan semua reservasi aktif                                         |
| 7   | Batalkan Reservasi | Membatalkan reservasi berdasarkan ID                                      |
| 0   | Keluar             | Keluar dari program                                                       |

## 💰 Tipe Kamar & Harga

| Tipe     | Harga/Malam  | Kapasitas |
| -------- | ------------ | --------- |
| Deluxe   | Rp 500.000   | 2 orang   |
| Superior | Rp 750.000   | 2 orang   |
| Suite    | Rp 1.200.000 | 4 orang   |

## 📚 Konsep OOP yang Digunakan

1. **Encapsulation**: Data dan method dikapsulkan dalam class (private/public)
2. **Inheritance**: `DeluxeRoom`, `SuperiorRoom`, `SuiteRoom` inherit dari `Room`
3. **Polymorphism**: Virtual destructor pada class `Room`
4. **Abstraction**: Interface yang jelas untuk setiap class
5. **Factory Pattern**: `RoomFactory` untuk membuat objek Room berdasarkan tipe

## 📝 Contoh Penggunaan

```
========================================
    Selamat datang di UGM Hotel!
    Alamat: Yogyakarta
========================================

Pilihan Anda: 3

+--------------------------------------+
|        TAMBAH CUSTOMER BARU          |
+--------------------------------------+
ID Customer akan otomatis: 1
Masukkan Nama: Budi Santoso
Masukkan Email: budi@email.com
Masukkan No. Telepon: 08123456789

>> Sukses: Customer Budi Santoso (ID: 1) berhasil ditambahkan!
```

## 👨‍💻 Pengembangan

Untuk melakukan modifikasi atau pengembangan:

1. Edit file header (.h) untuk menambah deklarasi
2. Edit file implementation (.cpp) untuk menambah implementasi
3. Compile ulang program
4. Test program untuk memastikan fungsionalitas

## 📄 Lisensi

Program ini dibuat untuk keperluan pembelajaran dan tugas akademik.

---

**Dibuat oleh**: Muhammad Khoirunas  
**Tanggal**: 19 Desember 2025  
**Mata Kuliah**: Object-Oriented Programming
