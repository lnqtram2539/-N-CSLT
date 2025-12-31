<<<<<<<< HEAD:CafeManagement/models/Customer.h
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
========
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

#endif
>>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76:models/Customer.h
