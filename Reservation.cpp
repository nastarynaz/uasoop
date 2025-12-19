#include "Reservation.h"
#include <iostream>

Reservation::Reservation(int id, Customer* c, Room* r, std::string in, std::string out)
    : idReservation(id), customer(c), room(r), checkInDate(in), checkOutDate(out) {
    // Buat Payment dengan referensi ke reservasi ini
    payment = new Payment(id + 100, r->price * 2); // Asumsi 2 malam
    payment->reservation = this;  // Set referensi ke reservation sesuai diagram
}

Reservation::~Reservation() {
    delete payment;
}

void Reservation::showReservationDetails() {
    std::cout << "Res #" << idReservation << " | " << customer->name 
              << " | Kamar: " << room->roomType << " (#" << room->idRoom << ")" 
              << " | " << checkInDate << " s/d " << checkOutDate;
    if (payment) {
        std::cout << " | Status Bayar: " << payment->paymentStatus;
    }
    std::cout << std::endl;
}

void Reservation::cancelReservation() {
    if (room) room->changeRoomStatus("Available");
}