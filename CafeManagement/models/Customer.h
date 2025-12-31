
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

struct Customer {
    string id;
    string name;
    int totalOrders;
};

// Quản lý khách hàng
void addCustomer(Customer*& customers, int& count);
void removeCustomer(Customer*& customers, int& count);

#endif // CUSTOMER_H
