#include "Hotel.h"
#include <iostream>

Hotel::Hotel(std::string name, std::string addr) 
    : hotelName(name), hotelAddress(addr), nextReservationId(1) {}

void Hotel::addRoom(Room* r) { roomList.push_back(r); }

void Hotel::showRoomList() {
    std::cout << "\n--- Daftar Kamar " << hotelName << " ---" << std::endl;
    for (size_t i = 0; i < roomList.size(); ++i) roomList[i]->showRoomDetails();
}

void Hotel::showReservationList() {
    std::cout << "\n--- Reservasi Aktif ---" << std::endl;
    if (reservationList.size() == 0) {
        std::cout << "Belum ada reservasi." << std::endl;
        return;
    }
    for (size_t i = 0; i < reservationList.size(); ++i) reservationList[i]->showReservationDetails();
}

// Cek apakah kamar tersedia pada tanggal tertentu
bool Hotel::isRoomAvailable(Room* r, std::string checkIn, std::string checkOut) {
    for (size_t i = 0; i < reservationList.size(); ++i) {
        Reservation* res = reservationList[i];
        if (res->room->idRoom == r->idRoom) {
            // Cek overlap tanggal (format: YYYY-MM-DD, bisa dibandingkan sebagai string)
            // Overlap jika: checkIn < existingOut DAN checkOut > existingIn
            if (checkIn < res->checkOutDate && checkOut > res->checkInDate) {
                return false;  // Ada overlap, kamar tidak tersedia
            }
        }
    }
    return true;  // Tidak ada overlap, kamar tersedia
}

void Hotel::createReservation(Customer* c, Room* r, std::string in, std::string out) {
    // Validasi ketersediaan berdasarkan tanggal
    if (!isRoomAvailable(r, in, out)) {
        std::cout << "Error: Kamar " << r->idRoom << " SUDAH DIPESAN pada tanggal tersebut!" << std::endl;
        return;
    }
    
    Reservation* res = new Reservation(nextReservationId, c, r, in, out);
    nextReservationId++;  // Increment counter untuk ID berikutnya
    reservationList.push_back(res);
    std::cout << "Sukses: Reservasi #" << res->idReservation << " untuk " << c->name << " berhasil." << std::endl;
}

void Hotel::cancelReservationById(int id) {
    for (std::vector<Reservation*>::iterator it = reservationList.begin(); it != reservationList.end(); ++it) {
        if ((*it)->idReservation == id) {
            (*it)->cancelReservation();
            delete *it;
            reservationList.erase(it);
            return;
        }
    }
}

Room* Hotel::getRoomById(int id) {
    for (size_t i = 0; i < roomList.size(); ++i) { if (roomList[i]->idRoom == id) return roomList[i]; }
    return NULL;
}

Reservation* Hotel::getReservationById(int id) {
    for (size_t i = 0; i < reservationList.size(); ++i) {
        if (reservationList[i]->idReservation == id) return reservationList[i];
    }
    return NULL;
}