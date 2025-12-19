#ifndef RESERVATION_H
#define RESERVATION_H
#include <string>
#include "Customer.h"
#include "Room.h"

class Payment {
public:
    int idPayment;
    double totalAmount;
    std::string paymentStatus;
    Payment(int id, double amount) : idPayment(id), totalAmount(amount), paymentStatus("Pending") {}
};

class Reservation {
public:
    int idReservation;
    Customer* customer;
    Room* room;
    std::string checkInDate;
    std::string checkOutDate;
    Payment* payment;

    Reservation(int id, Customer* c, Room* r, std::string in, std::string out);
    ~Reservation();
    void showReservationDetails();
    void cancelReservation();
};
#endif