<<<<<<<< HEAD:CafeManagement/models/Customer.cpp
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

    cin.ignore(); // 🔴 BẮT BUỘC

    cout << "Nhap ten khach hang: ";
    getline(cin, c.name);   // "Nguyen Van A"

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


void removeCustomer(Customer*& customers, int& count) {
    if (count == 0) {
        cout << "Danh sach khach hang rong!\n";
        return;
    }

    string id;
    cout << "Nhap ma khach hang can xoa: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Khong tim thay khach hang!\n";
        return;
    }

    Customer* newArr = new Customer[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            newArr[j++] = customers[i];
        }
    }

    delete[] customers;
    customers = newArr;
    count--;

    cout << "Xoa khach hang thanh cong!\n";
}
========
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

    cin.ignore(); // 🔴 BẮT BUỘC

    cout << "Nhap ten khach hang: ";
    getline(cin, c.name);   // "Nguyen Van A"

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


void removeCustomer(Customer*& customers, int& count) {
    if (count == 0) {
        cout << "Danh sach khach hang rong!\n";
        return;
    }

    string id;
    cout << "Nhap ma khach hang can xoa: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (customers[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Khong tim thay khach hang!\n";
        return;
    }

    Customer* newArr = new Customer[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            newArr[j++] = customers[i];
        }
    }

    delete[] customers;
    customers = newArr;
    count--;

    cout << "Xoa khach hang thanh cong!\n";
}
>>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76:models/Customer.cpp
