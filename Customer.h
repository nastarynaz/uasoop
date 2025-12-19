#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

class Customer {
public:
    int idCustomer;
    std::string name;
    std::string email;
    std::string phoneNumber;

    Customer(int id, std::string n, std::string e, std::string p);
    void showCustomerDetails();
};
#endif