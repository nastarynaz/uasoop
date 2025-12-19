#include "Reservation.h"
#include <iostream>

Reservation::Reservation(int id, Customer* c, Room* r, std::string in, std::string out)
    : idReservation(id), customer(c), room(r), checkInDate(in), checkOutDate(out) {
    payment = new Payment(id + 100, r->price * 2); // Asumsi 2 malam [cite: 106]
}

Reservation::~Reservation() {
    delete payment;
}

void Reservation::showReservationDetails() {
    std::cout << "Res #" << idReservation << " | " << customer->name 
              << " | Kamar: " << room->roomType << " (#" << room->idRoom << ")" 
              << " | " << checkInDate << " s/d " << checkOutDate << std::endl;
}

void Reservation::cancelReservation() {
    if (room) room->changeRoomStatus("Available");
}