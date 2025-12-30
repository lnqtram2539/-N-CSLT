#include "Customer.h"
#include <iostream>
using namespace std;

void addCustomer(Customer*& customers, int& count) {
    Customer c;

    cout << "Nhap ma khach hang: ";
    cin >> c.id;

    for (int i = 0; i < count; i++) {
        if (customers[i].id == c.id) {
            cout << "Ma khach hang da ton tai!\n";
            return;
        }
    }

    cin.ignore(); // ⚠️ BẮT BUỘC

    cout << "Nhap ten khach hang: ";
    getline(cin, c.name);

    c.totalOrders = 0;

    Customer* newArr = new Customer[count + 1];
    for (int i = 0; i < count; i++) {
        newArr[i] = customers[i];
    }

    newArr[count] = c;

    delete[] customers;
    customers = newArr;
    count++;

    cout << "Them khach hang thanh cong!\n";
}
