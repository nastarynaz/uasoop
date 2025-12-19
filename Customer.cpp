#include "Customer.h"
#include <iostream>

Customer::Customer(int id, std::string n, std::string e, std::string p)
    : idCustomer(id), name(n), email(e), phoneNumber(p) {}

void Customer::showCustomerDetails() {
    std::cout << "Customer: " << name << " (" << email << ")" << std::endl;
}