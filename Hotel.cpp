#include "Hotel.h"
#include <iostream>

Hotel::Hotel(std::string name, std::string addr) : hotelName(name), hotelAddress(addr) {}

void Hotel::addRoom(Room* r) { roomList.push_back(r); }

void Hotel::showRoomList() {
    std::cout << "\n--- Daftar Kamar " << hotelName << " ---" << std::endl;
    for (size_t i = 0; i < roomList.size(); ++i) roomList[i]->showRoomDetails();
}

void Hotel::showReservationList() {
    std::cout << "\n--- Reservasi Aktif ---" << std::endl;
    for (size_t i = 0; i < reservationList.size(); ++i) reservationList[i]->showReservationDetails();
}

void Hotel::createReservation(Customer* c, Room* r, std::string in, std::string out) {
    if (r->status == "Booked") {
        std::cout << "Error: Kamar " << r->idRoom << " SUDAH DIPESAN!" << std::endl;
        return;
    }
    Reservation* res = new Reservation(reservationList.size() + 1, c, r, in, out);
    r->changeRoomStatus("Booked");
    reservationList.push_back(res);
    std::cout << "Sukses: Reservasi untuk " << c->name << " berhasil." << std::endl;
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