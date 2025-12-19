#include <iostream>
#include <vector>
#include <limits>
#include "Hotel.h"

// Vector untuk menyimpan data customer
std::vector<Customer*> customerList;

// Counter untuk auto-generate ID
int nextRoomId = 104;  // Karena sudah ada kamar 101, 102, 103
int nextCustomerId = 1;

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showMenu() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "       SISTEM RESERVASI HOTEL UGM       " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "[1] Tambah Kamar Baru" << std::endl;
    std::cout << "[2] Lihat Daftar Kamar" << std::endl;
    std::cout << "[3] Tambah Customer Baru" << std::endl;
    std::cout << "[4] Lihat Daftar Customer" << std::endl;
    std::cout << "[5] Buat Reservasi" << std::endl;
    std::cout << "[6] Lihat Daftar Reservasi" << std::endl;
    std::cout << "[7] Batalkan Reservasi" << std::endl;
    std::cout << "[8] Konfirmasi Pembayaran" << std::endl;
    std::cout << "[0] Keluar" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "Pilihan Anda: ";
}

void addRoom(Hotel& hotel) {
    int typeChoice;
    std::string type;
    
    std::cout << "\n+--------------------------------------+" << std::endl;
    std::cout << "|         TAMBAH KAMAR BARU            |" << std::endl;
    std::cout << "+--------------------------------------+" << std::endl;
    std::cout << "ID Kamar akan otomatis: " << nextRoomId << std::endl;
    
    std::cout << "\nPilih Tipe Kamar:" << std::endl;
    std::cout << "[1] Deluxe   - Rp 500.000 (Kapasitas: 2)" << std::endl;
    std::cout << "[2] Superior - Rp 750.000 (Kapasitas: 2)" << std::endl;
    std::cout << "[3] Suite    - Rp 1.200.000 (Kapasitas: 4)" << std::endl;
    std::cout << "Pilihan: ";
    std::cin >> typeChoice;
    
    switch (typeChoice) {
        case 1: type = "Deluxe"; break;
        case 2: type = "Superior"; break;
        case 3: type = "Suite"; break;
        default:
            std::cout << "Error: Pilihan tidak valid!" << std::endl;
            return;
    }
    
    Room* newRoom = RoomFactory::createRoom(nextRoomId, type);
    if (newRoom != NULL) {
        hotel.addRoom(newRoom);
        std::cout << "\n>> Sukses: Kamar " << nextRoomId << " tipe " << type << " berhasil ditambahkan!" << std::endl;
        nextRoomId++;
    }
}

void addCustomer() {
    std::string name, email, phone;
    
    std::cout << "\n+--------------------------------------+" << std::endl;
    std::cout << "|        TAMBAH CUSTOMER BARU          |" << std::endl;
    std::cout << "+--------------------------------------+" << std::endl;
    std::cout << "ID Customer akan otomatis: " << nextCustomerId << std::endl;
    clearInput();
    
    std::cout << "Masukkan Nama: ";
    std::getline(std::cin, name);
    
    std::cout << "Masukkan Email: ";
    std::getline(std::cin, email);
    
    std::cout << "Masukkan No. Telepon: ";
    std::getline(std::cin, phone);
    
    Customer* newCustomer = new Customer(nextCustomerId, name, email, phone);
    customerList.push_back(newCustomer);
    std::cout << "\n>> Sukses: Customer " << name << " (ID: " << nextCustomerId << ") berhasil ditambahkan!" << std::endl;
    nextCustomerId++;
}

void showCustomerListNumbered() {
    std::cout << "\n+--------------------------------------+" << std::endl;
    std::cout << "|          DAFTAR CUSTOMER             |" << std::endl;
    std::cout << "+--------------------------------------+" << std::endl;
    if (customerList.size() == 0) {
        std::cout << "Belum ada customer terdaftar." << std::endl;
        return;
    }
    for (size_t i = 0; i < customerList.size(); ++i) {
        std::cout << "[" << (i + 1) << "] " << customerList[i]->name 
                  << " (ID: " << customerList[i]->idCustomer << ")" << std::endl;
    }
}

void createReservationMenu(Hotel& hotel) {
    int customerChoice, roomChoice;
    int checkInDay, checkInMonth, checkInYear;
    int checkOutDay, checkOutMonth, checkOutYear;
    char dateStr[20];
    std::string checkIn, checkOut;
    
    std::cout << "\n+--------------------------------------+" << std::endl;
    std::cout << "|         BUAT RESERVASI BARU          |" << std::endl;
    std::cout << "+--------------------------------------+" << std::endl;
    
    // Tampilkan daftar customer
    if (customerList.size() == 0) {
        std::cout << "Error: Belum ada customer. Silakan tambah customer terlebih dahulu." << std::endl;
        return;
    }
    
    std::cout << "\nPilih Customer:" << std::endl;
    for (size_t i = 0; i < customerList.size(); ++i) {
        std::cout << "[" << (i + 1) << "] " << customerList[i]->name 
                  << " - " << customerList[i]->email << std::endl;
    }
    std::cout << "Pilihan: ";
    std::cin >> customerChoice;
    
    if (customerChoice < 1 || customerChoice > (int)customerList.size()) {
        std::cout << "Error: Pilihan tidak valid!" << std::endl;
        return;
    }
    Customer* customer = customerList[customerChoice - 1];
    
    // Tampilkan daftar kamar dengan nomor
    std::cout << "\nPilih Kamar:" << std::endl;
    hotel.showRoomList();
    std::cout << "\nMasukkan ID Kamar yang dipilih: ";
    std::cin >> roomChoice;
    
    Room* room = hotel.getRoomById(roomChoice);
    if (room == NULL) {
        std::cout << "Error: Kamar tidak ditemukan!" << std::endl;
        return;
    }
    
    // Input tanggal check-in
    std::cout << "\n--- Tanggal Check-In ---" << std::endl;
    std::cout << "Pilih Tahun:" << std::endl;
    std::cout << "[1] 2025" << std::endl;
    std::cout << "[2] 2026" << std::endl;
    std::cout << "Pilihan: ";
    std::cin >> checkInYear;
    checkInYear = (checkInYear == 1) ? 2025 : 2026;
    
    std::cout << "Pilih Bulan (1-12): ";
    std::cin >> checkInMonth;
    
    std::cout << "Pilih Tanggal (1-31): ";
    std::cin >> checkInDay;
    
    snprintf(dateStr, sizeof(dateStr), "%d-%02d-%02d", checkInYear, checkInMonth, checkInDay);
    checkIn = dateStr;
    
    // Input tanggal check-out
    std::cout << "\n--- Tanggal Check-Out ---" << std::endl;
    std::cout << "Pilih Tahun:" << std::endl;
    std::cout << "[1] 2025" << std::endl;
    std::cout << "[2] 2026" << std::endl;
    std::cout << "Pilihan: ";
    std::cin >> checkOutYear;
    checkOutYear = (checkOutYear == 1) ? 2025 : 2026;
    
    std::cout << "Pilih Bulan (1-12): ";
    std::cin >> checkOutMonth;
    
    std::cout << "Pilih Tanggal (1-31): ";
    std::cin >> checkOutDay;
    
    snprintf(dateStr, sizeof(dateStr), "%d-%02d-%02d", checkOutYear, checkOutMonth, checkOutDay);
    checkOut = dateStr;
    
    std::cout << "\n--- Konfirmasi Reservasi ---" << std::endl;
    std::cout << "Customer : " << customer->name << std::endl;
    std::cout << "Kamar    : " << room->idRoom << " (" << room->roomType << ")" << std::endl;
    std::cout << "Check-In : " << checkIn << std::endl;
    std::cout << "Check-Out: " << checkOut << std::endl;
    std::cout << "\nKonfirmasi? [1] Ya  [2] Tidak" << std::endl;
    std::cout << "Pilihan: ";
    
    int confirm;
    std::cin >> confirm;
    
    if (confirm == 1) {
        hotel.createReservation(customer, room, checkIn, checkOut);
    } else {
        std::cout << "Reservasi dibatalkan." << std::endl;
    }
}

void cancelReservationMenu(Hotel& hotel) {
    int resId;
    
    std::cout << "\n+--------------------------------------+" << std::endl;
    std::cout << "|         BATALKAN RESERVASI           |" << std::endl;
    std::cout << "+--------------------------------------+" << std::endl;
    
    hotel.showReservationList();
    
    std::cout << "\nMasukkan ID Reservasi yang akan dibatalkan: ";
    std::cin >> resId;
    
    std::cout << "\nYakin ingin membatalkan? [1] Ya  [2] Tidak" << std::endl;
    std::cout << "Pilihan: ";
    
    int confirm;
    std::cin >> confirm;
    
    if (confirm == 1) {
        hotel.cancelReservationById(resId);
        std::cout << "\n>> Reservasi dengan ID " << resId << " telah dibatalkan." << std::endl;
    } else {
        std::cout << "Pembatalan dibatalkan." << std::endl;
    }
}

void confirmPaymentMenu(Hotel& hotel) {
    int resId;
    
    std::cout << "\n+--------------------------------------+" << std::endl;
    std::cout << "|       KONFIRMASI PEMBAYARAN          |" << std::endl;
    std::cout << "+--------------------------------------+" << std::endl;
    
    // Tampilkan daftar reservasi yang ada
    hotel.showReservationList();
    
    std::cout << "\nMasukkan ID Reservasi untuk konfirmasi pembayaran: ";
    std::cin >> resId;
    
    Reservation* res = hotel.getReservationById(resId);
    if (res == NULL) {
        std::cout << "Error: Reservasi tidak ditemukan!" << std::endl;
        return;
    }
    
    Payment* payment = res->getPayment();
    if (payment == NULL) {
        std::cout << "Error: Data pembayaran tidak ditemukan!" << std::endl;
        return;
    }
    
    std::cout << "\n--- Detail Pembayaran ---" << std::endl;
    std::cout << "ID Reservasi: " << res->idReservation << std::endl;
    std::cout << "Customer    : " << res->customer->name << std::endl;
    std::cout << "Kamar       : " << res->room->roomType << " (#" << res->room->idRoom << ")" << std::endl;
    std::cout << "Total Bayar : Rp " << payment->totalAmount << std::endl;
    std::cout << "Status      : " << payment->paymentStatus << std::endl;
    
    if (payment->paymentStatus == "Confirmed") {
        std::cout << "\n>> Pembayaran sudah dikonfirmasi sebelumnya." << std::endl;
        return;
    }
    
    std::cout << "\nKonfirmasi pembayaran? [1] Ya  [2] Tidak" << std::endl;
    std::cout << "Pilihan: ";
    
    int confirm;
    std::cin >> confirm;
    
    if (confirm == 1) {
        payment->confirmPayment();
    } else {
        std::cout << "Konfirmasi dibatalkan." << std::endl;
    }
}

int main() {
    Hotel myHotel("UGM Hotel", "Yogyakarta");
    int choice;
    
    // Setup data awal (3 kamar default)
    myHotel.addRoom(RoomFactory::createRoom(101, "Deluxe"));
    myHotel.addRoom(RoomFactory::createRoom(102, "Superior"));
    myHotel.addRoom(RoomFactory::createRoom(103, "Suite"));
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "    Selamat datang di " << myHotel.hotelName << "!" << std::endl;
    std::cout << "    Alamat: " << myHotel.hotelAddress << std::endl;
    std::cout << "========================================" << std::endl;
    
    do {
        showMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                addRoom(myHotel);
                break;
            case 2:
                myHotel.showRoomList();
                break;
            case 3:
                addCustomer();
                break;
            case 4:
                showCustomerListNumbered();
                break;
            case 5:
                createReservationMenu(myHotel);
                break;
            case 6:
                myHotel.showReservationList();
                break;
            case 7:
                cancelReservationMenu(myHotel);
                break;
            case 8:
                confirmPaymentMenu(myHotel);
                break;
            case 0:
                std::cout << "\n========================================" << std::endl;
                std::cout << "  Terima kasih telah menggunakan sistem" << std::endl;
                std::cout << "      reservasi " << myHotel.hotelName << "!" << std::endl;
                std::cout << "========================================" << std::endl;
                break;
            default:
                std::cout << "\n>> Pilihan tidak valid. Silakan pilih 0-8." << std::endl;
        }
    } while (choice != 0);
    
    // Cleanup memory
    for (size_t i = 0; i < customerList.size(); ++i) {
        delete customerList[i];
    }
    
    return 0;
}