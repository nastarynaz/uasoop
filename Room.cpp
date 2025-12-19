#include "Room.h"
#include <iostream>

Room::Room(int id, std::string type, double p, int cap) 
    : idRoom(id), roomType(type), price(p), status("Available"), capacity(cap) {}

void Room::showRoomDetails() {
    std::cout << "  - [ID: " << idRoom << "] " << roomType << " | Rp" << price 
              << " | Cap: " << capacity << " | Status: " << status << std::endl;
}

void Room::changeRoomStatus(std::string newStatus) {
    status = newStatus;
}

Room* RoomFactory::createRoom(int id, std::string type) {
    if (type == "Deluxe") return new DeluxeRoom(id);
    if (type == "Superior") return new SuperiorRoom(id);
    if (type == "Suite") return new SuiteRoom(id);
    return nullptr;
}