#include "Customer.h"
#include "Room.h"
#include <iostream>

Customer::Customer(int id, std::string n, std::string e, std::string p)
    : idCustomer(id), name(n), email(e), phoneNumber(p) {}

void Customer::showCustomerDetails() {
    std::cout << "Customer: " << name << " (" << email << ")" << std::endl;
}

void Customer::bookRoom(Room* room) {
    // Method untuk menunjukkan customer ingin booking kamar
    // Proses booking sebenarnya dilakukan melalui Hotel::createReservation
    std::cout << ">> Customer " << name << " memilih kamar " << room->idRoom 
              << " (" << room->roomType << ")" << std::endl;
}