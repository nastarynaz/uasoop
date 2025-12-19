#ifndef PAYMENT_H
#define PAYMENT_H
#include <string>

// Forward declaration untuk menghindari circular dependency
class Reservation;

class Payment {
public:
    int idPayment;
    Reservation* reservation;
    double totalAmount;
    std::string paymentStatus;

    Payment(int id, double amount);
    Payment(int id, Reservation* res);
    
    // Method sesuai diagram class
    double calculateTotalAmount();
    void confirmPayment();
    void showPaymentDetails();
};
#endif
