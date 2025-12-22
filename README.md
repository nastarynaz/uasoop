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

## 📋 Deskripsi

**Hotel Management System** adalah aplikasi berbasis CLI yang dirancang untuk mengelola operasional hotel secara efisien. Program ini mengimplementasikan konsep OOP secara lengkap termasuk **Encapsulation**, **Inheritance**, **Polymorphism**, dan **Design Pattern (Factory Pattern)**.

### ✨ Highlight
- 🔐 Sistem login dengan 2 role (Admin & Tamu)
- 🏠 Manajemen kamar dengan 3 tipe (Deluxe, Superior, Suite)
- 👥 Registrasi dan pengelolaan data customer
- 📅 Sistem reservasi lengkap dengan tanggal check-in/check-out
- 💳 Sistem pembayaran dengan konfirmasi
- 🔄 Pembatalan reservasi dengan status kamar otomatis

---

## � Sistem Login

Program memiliki 2 role pengguna dengan akses berbeda:

### 👨‍💼 Admin
Akses penuh ke semua fitur sistem.

| Menu | Fungsi |
|------|--------|
| [1] Tambah Kamar Baru | Menambah kamar dengan tipe Deluxe/Superior/Suite |
| [2] Lihat Daftar Kamar | Melihat semua kamar |
| [3] Cek Ketersediaan Kamar | Cek apakah kamar tersedia pada tanggal tertentu |
| [4] Tambah Customer Baru | Registrasi customer dengan nama, email, telepon |
| [5] Lihat Daftar Customer | Melihat semua customer terdaftar |
| [6] Buat Reservasi | Membuat reservasi baru |
| [7] Lihat Daftar Reservasi | Melihat semua reservasi aktif |
| [8] Batalkan Reservasi | Membatalkan reservasi yang ada |
| [9] Konfirmasi Pembayaran | Mengkonfirmasi pembayaran reservasi |
| [10] Logout | Kembali ke menu login |
| [0] Keluar | Keluar dari program |

### 👤 Tamu
Akses terbatas untuk melakukan reservasi.

| Menu | Fungsi |
|------|--------|
| [1] Lihat Daftar Kamar | Melihat kamar yang tersedia |
| [2] Cek Ketersediaan Kamar | Cek apakah kamar tersedia pada tanggal tertentu |
| [3] Daftar Sebagai Customer | Registrasi sebagai customer baru |
| [4] Buat Reservasi | Membuat reservasi kamar |
| [5] Lihat Reservasi Saya | Melihat daftar reservasi |
| [6] Batalkan Reservasi | Membatalkan reservasi sendiri |
| [9] Logout | Kembali ke menu login |
| [0] Keluar | Keluar dari program |

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
├── 📄 main.cpp              # Entry point, menu login, & menu interaktif
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

### Diagram Utama

```
┌──────────────────────────────────────────────────────────────────┐
│                             HOTEL                                 │
├──────────────────────────────────────────────────────────────────┤
│ - roomList: vector<Room*>                                         │
│ - reservationList: vector<Reservation*>                           │
│ + hotelName: string                                               │
│ + hotelAddress: string                                            │
├──────────────────────────────────────────────────────────────────┤
│ + Hotel(name, addr)                                               │
│ + addRoom(Room*)                                                  │
│ + showRoomList()                                                  │
│ + showReservationList()                                           │
│ + createReservation(Customer*, Room*, string, string)             │
│ + cancelReservationById(int)                                      │
│ + getRoomById(int): Room*                                         │
│ + getReservationById(int): Reservation*                           │
└────────────────────┬─────────────────────┬───────────────────────┘
                     │ aggregation 0..*    │ association 1
                     ▼                     ▼
┌─────────────────────────┐     ┌─────────────────────────────────┐
│          ROOM           │     │           CUSTOMER              │
├─────────────────────────┤     ├─────────────────────────────────┤
│ + idRoom: int           │     │ + idCustomer: int               │
│ + roomType: string      │     │ + name: string                  │
│ + price: double         │     │ + email: string                 │
│ + status: string        │     │ + phoneNumber: string           │
│ + capacity: int         │     ├─────────────────────────────────┤
├─────────────────────────┤     │ + Customer(id, name, email, phone) │
│ + Room(id, type, p, cap)│     │ + showCustomerDetails()         │
│ + virtual ~Room()       │     │ + bookRoom(Room*)               │
│ + showRoomDetails()     │     └────────────────┬────────────────┘
│ + changeRoomStatus()    │                      │ makes 0..*
└───────────┬─────────────┘                      ▼
            │                     ┌─────────────────────────────────┐
            │ inheritance         │         RESERVATION             │
            ▼                     ├─────────────────────────────────┤
   ┌────────┴────────┐            │ + idReservation: int            │
   │   SUBCLASSES    │            │ + customer: Customer*           │
   │                 │            │ + room: Room*                   │
┌──┴──┐ ┌────┴────┐ ┌┴────┐       │ + checkInDate: string           │
│Deluxe│ │Superior│ │Suite│       │ + checkOutDate: string          │
│Room  │ │Room    │ │Room │       │ + payment: Payment*             │
└──────┘ └────────┘ └─────┘       ├─────────────────────────────────┤
                                  │ + Reservation(id, c, r, in, out)│
                                  │ + ~Reservation()                │
                                  │ + showReservationDetails()      │
                                  │ + cancelReservation()           │
                                  │ + getPayment(): Payment*        │
                                  └────────────────┬────────────────┘
                                                   │ composition 1
                                                   ▼
                                  ┌─────────────────────────────────┐
                                  │           PAYMENT               │
                                  ├─────────────────────────────────┤
                                  │ + idPayment: int                │
                                  │ + reservation: Reservation*     │
                                  │ + totalAmount: double           │
                                  │ + paymentStatus: string         │
                                  ├─────────────────────────────────┤
                                  │ + Payment(id, amount)           │
                                  │ + Payment(id, Reservation*)     │
                                  │ + calculateTotalAmount(): double│
                                  │ + confirmPayment()              │
                                  │ + showPaymentDetails()          │
                                  └─────────────────────────────────┘
```

### RoomFactory (Factory Pattern)

```
┌─────────────────────────────────────┐
│           ROOMFACTORY               │
├─────────────────────────────────────┤
│ + static createRoom(id, type): Room*│
└─────────────────────────────────────┘
         │
         │ creates
         ▼
    ┌────┴────┐
    │  Room   │
    └────┬────┘
         │
    ┌────┼────┐
    ▼    ▼    ▼
Deluxe Superior Suite
```

---

## 🔗 Relasi Antarkelas

| Relasi | Kelas | Deskripsi |
|--------|-------|-----------|
| **Inheritance** | Room → DeluxeRoom, SuperiorRoom, SuiteRoom | Pewarisan atribut dan method dasar |
| **Aggregation** | Hotel ◇→ Room | Hotel memiliki kumpulan Room |
| **Composition** | Reservation ◆→ Payment | Payment tidak ada tanpa Reservation |
| **Association** | Customer ──→ Reservation | Customer membuat Reservation |

---

## �🛠️ Instalasi

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

### Menu Login

```
========================================
       SISTEM RESERVASI HOTEL UGM       
========================================
         Silakan Login Sebagai:         
========================================
[1] Admin
[2] Tamu
[0] Keluar
========================================
Pilihan Anda: _
```

### 📝 Contoh Alur Penggunaan (Admin)

```
1️⃣  Login sebagai Admin [1]
2️⃣  Pilih [3] → Tambah customer "Budi Santoso"
3️⃣  Pilih [5] → Buat reservasi untuk Budi, kamar Suite
4️⃣  Pilih [6] → Lihat reservasi (Status: Pending)
5️⃣  Pilih [8] → Konfirmasi pembayaran
6️⃣  Pilih [6] → Lihat reservasi (Status: Confirmed) ✅
7️⃣  Pilih [9] → Logout
```

### 📝 Contoh Alur Penggunaan (Tamu)

```
1️⃣  Login sebagai Tamu [2]
2️⃣  Pilih [1] → Lihat kamar yang tersedia
3️⃣  Pilih [2] → Daftar sebagai customer
4️⃣  Pilih [3] → Buat reservasi
5️⃣  Pilih [4] → Lihat reservasi saya
6️⃣  Pilih [9] → Logout
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
# 1. Login sebagai Admin
# 2. Tambah customer
# 3. Lihat kamar default (101, 102, 103)
# 4. Buat reservasi
# 5. Konfirmasi pembayaran
# 6. Batalkan reservasi
# 7. Logout dan login sebagai Tamu
```

---

## 📋 Daftar Fungsi

### Hotel Class
| Method | Deskripsi |
|--------|-----------|
| `Hotel(name, addr)` | Constructor |
| `addRoom(Room*)` | Menambah kamar ke hotel |
| `showRoomList()` | Menampilkan daftar kamar |
| `showReservationList()` | Menampilkan daftar reservasi |
| `createReservation(Customer*, Room*, in, out)` | Membuat reservasi baru |
| `cancelReservationById(int)` | Membatalkan reservasi |
| `getRoomById(int)` | Mendapatkan kamar berdasarkan ID |
| `getReservationById(int)` | Mendapatkan reservasi berdasarkan ID |

### Room Class
| Method | Deskripsi |
|--------|-----------|
| `Room(id, type, p, cap)` | Constructor |
| `virtual ~Room()` | Virtual destructor |
| `showRoomDetails()` | Menampilkan detail kamar |
| `changeRoomStatus(newStatus)` | Mengubah status kamar |

### Customer Class
| Method | Deskripsi |
|--------|-----------|
| `Customer(id, n, e, p)` | Constructor |
| `showCustomerDetails()` | Menampilkan detail customer |
| `bookRoom(Room*)` | Memilih kamar untuk booking |

### Reservation Class
| Method | Deskripsi |
|--------|-----------|
| `Reservation(id, c, r, in, out)` | Constructor + buat Payment |
| `~Reservation()` | Destructor + hapus Payment |
| `showReservationDetails()` | Menampilkan detail reservasi |
| `cancelReservation()` | Mengubah status kamar ke Available |
| `getPayment()` | Getter untuk objek Payment |

### Payment Class
| Method | Deskripsi |
|--------|-----------|
| `Payment(id, amount)` | Constructor dengan amount |
| `Payment(id, Reservation*)` | Constructor dengan Reservation |
| `calculateTotalAmount()` | Menghitung total pembayaran |
| `confirmPayment()` | Mengkonfirmasi pembayaran |
| `showPaymentDetails()` | Menampilkan detail pembayaran |

### RoomFactory Class
| Method | Deskripsi |
|--------|-----------|
| `static createRoom(id, type)` | Factory method untuk membuat Room |

---

## 📝 Catatan Pengembangan

| Versi | Tanggal | Perubahan |
|-------|---------|-----------|
| 1.0 | 19 Des 2024 | Initial release dengan fitur dasar |
| 1.1 | 19 Des 2024 | Tambah class Payment terpisah + konfirmasi pembayaran |
| 1.2 | 22 Des 2024 | Tambah sistem login Admin/Tamu + menu terpisah per role |

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
