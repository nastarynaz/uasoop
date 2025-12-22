#ifndef HOTEL_H
#define HOTEL_H
#include <vector>
#include <string>
#include "Room.h"
#include "Reservation.h"

class Hotel {
private:
    std::vector<Room*> roomList;
    std::vector<Reservation*> reservationList;
    int nextReservationId;  // Counter untuk ID reservasi yang unik
public:
    std::string hotelName;
    std::string hotelAddress;

    Hotel(std::string name, std::string addr);
    void addRoom(Room* r);
    void showRoomList();
    void showReservationList();
    bool isRoomAvailable(Room* r, std::string checkIn, std::string checkOut);
    void createReservation(Customer* c, Room* r, std::string in, std::string out);
    void cancelReservationById(int id);
    Room* getRoomById(int id);
    Reservation* getReservationById(int id);
};
#endif