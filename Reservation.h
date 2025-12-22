#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include "Customer.h"
#include "Room.h"
#include "Payment.h"

class Reservation {
public:
    Payment* payment;
    int idReservation;
    Customer* customer;
    Room* room;
    std::string checkInDate;
    std::string checkOutDate;

    Reservation(int id, Customer* c, Room* r, std::string in, std::string out);
    ~Reservation();
    void showReservationDetails();
    void cancelReservation();
    
    // Getter untuk Payment
    Payment* getPayment() { return payment; }
};
#endif