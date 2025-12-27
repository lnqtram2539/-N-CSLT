#include "FileHandler.h"
#include <fstream>

// ================= PRODUCT =================
vector<Product> loadProducts() {
    vector<Product> products;
    ifstream file("data/products.txt");

    if (!file.is_open()) return products;

    Product p;
    while (file >> p.id >> p.name >> p.category >> p.price >> p.stock) {
        products.push_back(p);
    }

    file.close();
    return products;
}

void saveProducts(const vector<Product>& products) {
    ofstream file("data/products.txt");

    for (auto p : products) {
        file << p.id << " "
             << p.name << " "
             << p.category << " "
             << p.price << " "
             << p.stock << endl;
    }

    file.close();
}

// ================= CUSTOMER =================
vector<Customer> loadCustomers() {
    vector<Customer> customers;
    ifstream file("data/customers.txt");

    if (!file.is_open()) return customers;

    Customer c;
    while (file >> c.id >> c.name >> c.totalOrders) {
        customers.push_back(c);
    }

    file.close();
    return customers;
}

void saveCustomers(const vector<Customer>& customers) {
    ofstream file("data/customers.txt");

    for (auto c : customers) {
        file << c.id << " "
             << c.name << " "
             << c.totalOrders << endl;
    }

    file.close();
}

// ================= STAFF =================
vector<Staff> loadStaffs() {
    vector<Staff> staffs;
    ifstream file("data/staffs.txt");

    if (!file.is_open()) return staffs;

    Staff s;
    while (file >> s.id >> s.name >> s.totalOrders) {
        staffs.push_back(s);
    }

    file.close();
    return staffs;
}

void saveStaffs(const vector<Staff>& staffs) {
    ofstream file("data/staffs.txt");

    for (auto s : staffs) {
        file << s.id << " "
             << s.name << " "
             << s.totalOrders << endl;
    }

    file.close();
}
