#include "FileHandler.h"
#include <fstream>

// ================= PRODUCT =================
Product* loadProducts(int& count) {
    ifstream file("data/products.txt");
    count = 0;
    Product* products = nullptr;

    Product temp;
    while (file >> temp.id >> temp.name >> temp.category >> temp.price >> temp.stock) {
        Product* newArray = new Product[count + 1];
        for (int i = 0; i < count; i++) {
            newArray[i] = products[i];
        }
        newArray[count] = temp;
        delete[] products;
        products = newArray;
        count++;
    }

    return products;
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
