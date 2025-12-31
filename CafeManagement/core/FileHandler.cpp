#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

<<<<<<< HEAD
// ================= PRODUCT =================
void loadProducts(Product*& products, int& count) {
    ifstream file("C:/-N-CSLT/data/products.txt");

    if (!file.is_open()) {
        cout << "❌ KHONG MO DUOC FILE products.txt\n";
        products = nullptr;
        count = 0;
        return;
    }

    cout << "✅ DA MO DUOC FILE products.txt\n";

    count = 0;
    string line;

    while (getline(file, line)) {
        if (line != "") count++;
    }

=======
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
>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76
    file.clear();
    file.seekg(0);

    products = new Product[count];
    int i = 0;

<<<<<<< HEAD
    while (getline(file, line)) {
        if (line == "") continue;

        stringstream ss(line);
        getline(ss, products[i].id, '|');
        getline(ss, products[i].name, '|');
        getline(ss, products[i].category, '|');
        ss >> products[i].price;

        products[i].stock = 0;
=======
    while (std::getline(file, line)) {
        stringstream ss(line);
        std::getline(ss, products[i].id, '|');
        std::getline(ss, products[i].name, '|');
        std::getline(ss, products[i].category, '|');
        ss >> products[i].price;
        ss.ignore();
        ss >> products[i].stock;
>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76
        i++;
    }

    file.close();
<<<<<<< HEAD

    cout << "👉 SO SAN PHAM LOAD DUOC: " << count << endl;
}


void saveProducts(Product* products, int count) {
    ofstream file("C:/-N-CSLT/data/products.txt");
=======
}

void saveProducts(Product* products, int count) {
    ofstream file("data/products.txt");
>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76
    for (int i = 0; i < count; i++) {
        file << products[i].id << "|"
             << products[i].name << "|"
             << products[i].category << "|"
<<<<<<< HEAD
             << products[i].price << "\n";
=======
             << products[i].price << "|"
             << products[i].stock << "\n";
>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76
    }
    file.close();
}

<<<<<<< HEAD
// ================= CUSTOMER =================
void loadCustomers(Customer*& customers, int& count) {
    ifstream file("C:/-N-CSLT/data/customers.txt");
    if (!file.is_open()) {
        cout << "Khong mo duoc customers.txt\n";
        count = 0;
        return;
    }

    count = 0;
    string line;
    while (getline(file, line)) count++;

=======
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
>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76
    file.clear();
    file.seekg(0);

    customers = new Customer[count];
    int i = 0;

<<<<<<< HEAD
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, customers[i].id, '|');
        getline(ss, customers[i].name, '|');
        ss >> customers[i].totalOrders;
        i++;
    }
=======
    while (std::getline(file, line)) {
        stringstream ss(line);
        std::getline(ss, customers[i].id, '|');
        std::getline(ss, customers[i].name, '|');
        ss >> customers[i].totalOrders;
        i++;
    }

>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76
    file.close();
}

void saveCustomers(Customer* customers, int count) {
<<<<<<< HEAD
    ofstream file("C:/-N-CSLT/data/customers.txt");
=======
    ofstream file("data/customers.txt");
>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76
    for (int i = 0; i < count; i++) {
        file << customers[i].id << "|"
             << customers[i].name << "|"
             << customers[i].totalOrders << "\n";
    }
    file.close();
}

<<<<<<< HEAD
// ================= STAFF =================
void loadStaffs(Staff*& staffs, int& count) {
    ifstream file("C:/-N-CSLT/data/staffs.txt");
    if (!file.is_open()) {
        cout << "Khong mo duoc staffs.txt\n";
        count = 0;
        return;
    }

    count = 0;
    string line;
    while (getline(file, line)) count++;

=======
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
>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76
    file.clear();
    file.seekg(0);

    staffs = new Staff[count];
    int i = 0;

<<<<<<< HEAD
    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, staffs[i].id, '|');
        getline(ss, staffs[i].name, '|');
        ss >> staffs[i].totalOrders;
        i++;
    }
=======
    while (std::getline(file, line)) {
        stringstream ss(line);
        std::getline(ss, staffs[i].id, '|');
        std::getline(ss, staffs[i].name, '|');
        ss >> staffs[i].totalOrders;
        i++;
    }

>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76
    file.close();
}

void saveStaffs(Staff* staffs, int count) {
<<<<<<< HEAD
    ofstream file("C:/-N-CSLT/data/staffs.txt");
=======
    ofstream file("data/staffs.txt");
>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76
    for (int i = 0; i < count; i++) {
        file << staffs[i].id << "|"
             << staffs[i].name << "|"
             << staffs[i].totalOrders << "\n";
    }
    file.close();
}
<<<<<<< HEAD
=======

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
>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76
