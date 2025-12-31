#ifndef BILL_H
#define BILL_H

#include <string>
using namespace std;

struct Bill {
    string billId;
    string date;        // YYYY-MM-DD
    string productId;
    int quantity;
    double totalPrice;
    string staffId;
    double totalAmount;
};

#endif
