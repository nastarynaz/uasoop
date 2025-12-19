# 🏨 Hotel Management System

<div align="center">

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![OOP](https://img.shields.io/badge/OOP-Design_Pattern-green?style=for-the-badge)
![License](https://img.shields.io/badge/License-Academic-blue?style=for-the-badge)

**Sistem Manajemen Hotel berbasis Command Line Interface (CLI)**  
*Dibangun dengan C++ menggunakan prinsip Object-Oriented Programming*

[Fitur](#-fitur) • [Instalasi](#-instalasi) • [Penggunaan](#-cara-penggunaan) • [Struktur](#-struktur-project) • [OOP Concepts](#-konsep-oop-yang-diterapkan)

</div>

---

## � Deskripsi

**Hotel Management System** adalah aplikasi berbasis CLI yang dirancang untuk mengelola operasional hotel secara efisien. Program ini mengimplementasikan konsep OOP secara lengkap termasuk **Encapsulation**, **Inheritance**, **Polymorphism**, dan **Design Pattern (Factory Pattern)**.

### ✨ Highlight
- 🏠 Manajemen kamar dengan 3 tipe (Deluxe, Superior, Suite)
- 👥 Registrasi dan pengelolaan data customer
- 📅 Sistem reservasi lengkap dengan tanggal check-in/check-out
- 💳 Sistem pembayaran dengan konfirmasi
- 🔄 Pembatalan reservasi dengan status kamar otomatis

---

## 🚀 Fitur

| Fitur | Deskripsi |
|-------|-----------|
| **Tambah Kamar** | Menambah kamar baru dengan ID otomatis (Deluxe/Superior/Suite) |
| **Lihat Kamar** | Menampilkan semua kamar dengan status (Available/Booked) |
| **Tambah Customer** | Registrasi customer baru dengan nama, email, dan telepon |
| **Lihat Customer** | Daftar semua customer yang terdaftar |
| **Buat Reservasi** | Membuat reservasi dengan memilih customer dan kamar |
| **Lihat Reservasi** | Menampilkan reservasi aktif dengan status pembayaran |
| **Batalkan Reservasi** | Membatalkan reservasi dan mengembalikan status kamar |
| **Konfirmasi Pembayaran** | Mengkonfirmasi pembayaran untuk reservasi |

---

## 💰 Tipe Kamar & Harga

| Tipe | Harga/Malam | Kapasitas | Fasilitas |
|------|-------------|-----------|-----------|
| 🛏️ **Deluxe** | Rp 500.000 | 2 orang | Standard room dengan AC |
| ⭐ **Superior** | Rp 750.000 | 2 orang | Kamar lebih luas + TV |
| 👑 **Suite** | Rp 1.200.000 | 4 orang | Living room terpisah |

---

## 📁 Struktur Project

```
Tugas_OOP_Hotel/
│
├── 📄 main.cpp              # Entry point & menu interaktif
│
├── 🏨 Hotel.h / Hotel.cpp   # Class Hotel (agregator utama)
│
├── 🚪 Room.h / Room.cpp     # Class Room + subclass (Deluxe, Superior, Suite)
│                            # + RoomFactory (Factory Pattern)
│
├── 👤 Customer.h / Customer.cpp  # Class Customer
│
├── 📅 Reservation.h / Reservation.cpp  # Class Reservation
│
├── 💳 Payment.h / Payment.cpp    # Class Payment
│
├── 📜 Pakta_Integritas.txt  # Dokumen integritas akademik
│
└── 📖 README.md             # Dokumentasi ini
```

---

## 🏗️ Class Diagram

```
┌──────────────────────────────────────────────────────────────────┐
│                             HOTEL                                 │
├──────────────────────────────────────────────────────────────────┤
│ - roomList: vector<Room*>                                         │
│ - reservationList: vector<Reservation*>                           │
│ + hotelName: string                                               │
│ + hotelAddress: string                                            │
├──────────────────────────────────────────────────────────────────┤
│ + showRoomList()                                                  │
│ + showReservationList()                                           │
│ + createReservation(Customer*, Room*, string, string)             │
│ + cancelReservationById(int)                                      │
│ + getRoomById(int): Room*                                         │
│ + getReservationById(int): Reservation*                           │
└────────────────────┬─────────────────────┬───────────────────────┘
                     │ has 0..*            │ 1
                     ▼                     ▼
┌─────────────────────────┐     ┌─────────────────────────────────┐
│          ROOM           │     │           CUSTOMER              │
├─────────────────────────┤     ├─────────────────────────────────┤
│ + idRoom: int           │     │ + idCustomer: int               │
│ + roomType: string      │     │ + name: string                  │
│ + price: double         │     │ + email: string                 │
│ + status: string        │     │ + phoneNumber: string           │
│ + capacity: int         │     ├─────────────────────────────────┤
├─────────────────────────┤     │ + showCustomerDetails()         │
│ + showRoomDetails()     │     │ + bookRoom(Room*)               │
│ + changeRoomStatus()    │     └────────────────┬────────────────┘
└───────────┬─────────────┘                      │ makes 0..*
            │                                    ▼
            │ contains 1          ┌─────────────────────────────────┐
            │                     │         RESERVATION             │
            ▼                     ├─────────────────────────────────┤
   ┌────────┴────────┐            │ + idReservation: int            │
   │   INHERITANCE   │            │ + customer: Customer*           │
   │                 │            │ + room: Room*                   │
┌──┴──┐ ┌────┴────┐ ┌┴────┐       │ + checkInDate: string           │
│Deluxe│ │Superior│ │Suite│       │ + checkOutDate: string          │
│Room  │ │Room    │ │Room │       │ + payment: Payment*             │
└──────┘ └────────┘ └─────┘       ├─────────────────────────────────┤
                                  │ + showReservationDetails()      │
                                  │ + cancelReservation()           │
                                  └────────────────┬────────────────┘
                                                   │ has 1
                                                   ▼
                                  ┌─────────────────────────────────┐
                                  │           PAYMENT               │
                                  ├─────────────────────────────────┤
                                  │ + idPayment: int                │
                                  │ + reservation: Reservation*     │
                                  │ + totalAmount: double           │
                                  │ + paymentStatus: string         │
                                  ├─────────────────────────────────┤
                                  │ + calculateTotalAmount()        │
                                  │ + confirmPayment()              │
                                  │ + showPaymentDetails()          │
                                  └─────────────────────────────────┘
```

---

## 🛠️ Instalasi

### Prerequisites
- **Compiler C++**: g++ (GCC) atau clang++
- **C++ Standard**: C++11 atau lebih baru

### Install Compiler

<details>
<summary><b>macOS</b></summary>

```bash
xcode-select --install
```
</details>

<details>
<summary><b>Linux (Ubuntu/Debian)</b></summary>

```bash
sudo apt update && sudo apt install g++
```
</details>

<details>
<summary><b>Windows</b></summary>

Install [MinGW-w64](https://www.mingw-w64.org/) atau gunakan Visual Studio dengan C++ workload.
</details>

### Compile Program

```bash
g++ -o hotel_program main.cpp Customer.cpp Hotel.cpp Reservation.cpp Room.cpp Payment.cpp
```

---

## 🎮 Cara Penggunaan

### Jalankan Program

**macOS/Linux:**
```bash
./hotel_program
```

**Windows:**
```bash
hotel_program.exe
```

### Menu Utama

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
[8] Konfirmasi Pembayaran
[0] Keluar
========================================
Pilihan Anda: _
```

### 📝 Contoh Alur Penggunaan

```
1️⃣  Pilih [3] → Tambah customer "Budi Santoso"
2️⃣  Pilih [5] → Buat reservasi untuk Budi, kamar Suite
3️⃣  Pilih [6] → Lihat reservasi (Status: Pending)
4️⃣  Pilih [8] → Konfirmasi pembayaran
5️⃣  Pilih [6] → Lihat reservasi (Status: Confirmed) ✅
```

---

## 📚 Konsep OOP yang Diterapkan

### 1. 🔒 Encapsulation
Data disembunyikan dengan akses modifier `private` dan diakses melalui method `public`.

```cpp
class Hotel {
private:
    std::vector<Room*> roomList;        // Hidden data
    std::vector<Reservation*> reservationList;
public:
    void showRoomList();                // Public interface
    Room* getRoomById(int id);
};
```

### 2. 🧬 Inheritance
Subclass `DeluxeRoom`, `SuperiorRoom`, `SuiteRoom` mewarisi dari base class `Room`.

```cpp
class Room { /* base class */ };

class DeluxeRoom : public Room {
    DeluxeRoom(int id) : Room(id, "Deluxe", 500000.0, 2) {}
};
```

### 3. 🎭 Polymorphism
Virtual destructor memungkinkan proper cleanup untuk derived classes.

```cpp
class Room {
public:
    virtual ~Room() {}  // Virtual destructor
};
```

### 4. 🏭 Factory Pattern
`RoomFactory` membuat objek Room berdasarkan tipe yang diminta.

```cpp
class RoomFactory {
public:
    static Room* createRoom(int id, std::string type) {
        if (type == "Deluxe") return new DeluxeRoom(id);
        if (type == "Superior") return new SuperiorRoom(id);
        if (type == "Suite") return new SuiteRoom(id);
        return nullptr;
    }
};
```

### 5. 🔗 Association & Aggregation
- **Hotel** memiliki banyak **Room** (Aggregation)
- **Reservation** terhubung dengan **Customer** dan **Room** (Association)
- **Reservation** memiliki **Payment** (Composition)

---

## 🧪 Testing

Untuk memastikan program berjalan dengan benar:

```bash
# Compile
g++ -o hotel_program main.cpp Customer.cpp Hotel.cpp Reservation.cpp Room.cpp Payment.cpp

# Run
./hotel_program

# Test scenario:
# 1. Tambah customer
# 2. Lihat kamar default (101, 102, 103)
# 3. Buat reservasi
# 4. Konfirmasi pembayaran
# 5. Batalkan reservasi
```

---

## � Catatan Pengembangan

| Versi | Tanggal | Perubahan |
|-------|---------|-----------|
| 1.0 | 19 Des 2024 | Initial release dengan fitur dasar |
| 1.1 | 19 Des 2024 | Tambah class Payment terpisah + konfirmasi pembayaran |

---

## 👨‍💻 Author

<table>
<tr>
<td align="center">
<b>Muhammad Khoirunas</b><br>
<sub>Object-Oriented Programming</sub>
</td>
</tr>
</table>

---

## 📄 Lisensi

Program ini dibuat untuk keperluan **pembelajaran dan tugas akademik**.

---

<div align="center">

**⭐ UGM Hotel Management System ⭐**

*Dibuat dengan ❤️ menggunakan C++ dan prinsip OOP*

</div>
