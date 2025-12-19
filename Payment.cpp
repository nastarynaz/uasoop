#include "Payment.h"
#include <iostream>

// Forward declaration - akan di-include nanti setelah Reservation di-update
class Reservation;

Payment::Payment(int id, double amount) 
    : idPayment(id), reservation(nullptr), totalAmount(amount), paymentStatus("Pending") {}

Payment::Payment(int id, Reservation* res) 
    : idPayment(id), reservation(res), totalAmount(0.0), paymentStatus("Pending") {
    // Total amount akan dihitung saat calculateTotalAmount() dipanggil
}

double Payment::calculateTotalAmount() {
    // Jika reservation sudah di-set, hitung berdasarkan room price dan durasi
    // Untuk saat ini, return totalAmount yang sudah di-set
    return totalAmount;
}

void Payment::confirmPayment() {
    if (paymentStatus == "Pending") {
        paymentStatus = "Confirmed";
        std::cout << ">> Pembayaran ID " << idPayment << " telah dikonfirmasi." << std::endl;
        std::cout << "   Total: Rp " << totalAmount << std::endl;
    } else if (paymentStatus == "Confirmed") {
        std::cout << ">> Pembayaran sudah dikonfirmasi sebelumnya." << std::endl;
    } else {
        std::cout << ">> Error: Status pembayaran tidak valid." << std::endl;
    }
}

void Payment::showPaymentDetails() {
    std::cout << "  Payment #" << idPayment 
              << " | Total: Rp " << totalAmount 
              << " | Status: " << paymentStatus << std::endl;
}
