#ifndef ROOM_H
#define ROOM_H
#include <string>

class Room {
public:
    int idRoom;
    std::string roomType;
    double price;
    std::string status;
    int capacity;

    Room(int id, std::string type, double p, int cap);
    virtual ~Room() {}
    
    void showRoomDetails();
    void changeRoomStatus(std::string newStatus);
};

class DeluxeRoom : public Room {
public:
    DeluxeRoom(int id) : Room(id, "Deluxe", 500000.0, 2) {}
};

class SuperiorRoom : public Room {
public:
    SuperiorRoom(int id) : Room(id, "Superior", 750000.0, 2) {}
};

class SuiteRoom : public Room {
public:
    SuiteRoom(int id) : Room(id, "Suite", 1200000.0, 4) {}
};

class RoomFactory {
public:
    static Room* createRoom(int id, std::string type);
};
#endif