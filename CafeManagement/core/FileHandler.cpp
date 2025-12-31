#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

/* ================= PRODUCT ================= */

void loadProducts(Product*& products, int& count) {
    ifstream file("data/products.txt");
    count = 0;
    string line;

    if (!file.is_open()) {
        products = nullptr;
        return;
    }

    while (std::getline(file, line)) count++;
    file.clear();
    file.seekg(0);

    products = new Product[count];
    int i = 0;

    while (std::getline(file, line)) {
        stringstream ss(line);
        std::getline(ss, products[i].id, '|');
        std::getline(ss, products[i].name, '|');
        std::getline(ss, products[i].category, '|');
        ss >> products[i].price;
        ss.ignore();
        ss >> products[i].stock;
        i++;
    }

    file.close();
}

void saveProducts(Product* products, int count) {
    ofstream file("data/products.txt");
    for (int i = 0; i < count; i++) {
        file << products[i].id << "|"
             << products[i].name << "|"
             << products[i].category << "|"
             << products[i].price << "|"
             << products[i].stock << "\n";
    }
    file.close();
}

/* ================= CUSTOMER ================= */

void loadCustomers(Customer*& customers, int& count) {
    ifstream file("data/customers.txt");
    count = 0;
    string line;

    if (!file.is_open()) {
        customers = nullptr;
        return;
    }

    while (std::getline(file, line)) count++;
    file.clear();
    file.seekg(0);

    customers = new Customer[count];
    int i = 0;

    while (std::getline(file, line)) {
        stringstream ss(line);
        std::getline(ss, customers[i].id, '|');
        std::getline(ss, customers[i].name, '|');
        ss >> customers[i].totalOrders;
        i++;
    }

    file.close();
}

void saveCustomers(Customer* customers, int count) {
    ofstream file("data/customers.txt");
    for (int i = 0; i < count; i++) {
        file << customers[i].id << "|"
             << customers[i].name << "|"
             << customers[i].totalOrders << "\n";
    }
    file.close();
}

/* ================= STAFF ================= */

void loadStaffs(Staff*& staffs, int& count) {
    ifstream file("data/staffs.txt");
    count = 0;
    string line;

    if (!file.is_open()) {
        staffs = nullptr;
        return;
    }

    while (std::getline(file, line)) count++;
    file.clear();
    file.seekg(0);

    staffs = new Staff[count];
    int i = 0;

    while (std::getline(file, line)) {
        stringstream ss(line);
        std::getline(ss, staffs[i].id, '|');
        std::getline(ss, staffs[i].name, '|');
        ss >> staffs[i].totalOrders;
        i++;
    }

    file.close();
}

void saveStaffs(Staff* staffs, int count) {
    ofstream file("data/staffs.txt");
    for (int i = 0; i < count; i++) {
        file << staffs[i].id << "|"
             << staffs[i].name << "|"
             << staffs[i].totalOrders << "\n";
    }
    file.close();
}

/* ================= BILL ================= */

void loadBills(Bill*& bills, int& count) {
    ifstream file("data/bills.txt");
    count = 0;
    string line;

    if (!file.is_open()) {
        bills = nullptr;
        return;
    }

    while (std::getline(file, line)) count++;
    file.clear();
    file.seekg(0);

    bills = new Bill[count];
    int i = 0;

    while (std::getline(file, line)) {
        stringstream ss(line);
        std::getline(ss, bills[i].billId, '|');
        std::getline(ss, bills[i].date, '|');
        std::getline(ss, bills[i].productId, '|');
        ss >> bills[i].quantity;
        ss.ignore();
        ss >> bills[i].totalPrice;
        ss.ignore();
        std::getline(ss, bills[i].staffId);
        i++;
    }

    file.close();
}

void saveBills(Bill* bills, int count) {
    ofstream file("data/bills.txt");
    for (int i = 0; i < count; i++) {
        file << bills[i].billId << "|"
             << bills[i].date << "|"
             << bills[i].productId << "|"
             << bills[i].quantity << "|"
             << bills[i].totalPrice << "|"
             << bills[i].staffId << "\n";
    }
    file.close();
}
