#include "FileHandler.h"
#include <fstream>
#include <sstream>

// ================= PRODUCT =================
void loadProducts(Product*& products, int& count) {
    ifstream file("C:/-N-CSLT/data/products.txt");
    count = 0;
    string line;

    while (getline(file, line)) count++;

    file.clear();
    file.seekg(0);

    products = new Product[count];
    int i = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, products[i].id, '|');
        getline(ss, products[i].name, '|');
        getline(ss, products[i].category, '|');
        ss >> products[i].price;
        i++;
    }
    file.close();

void saveProducts(Product* products, int count) {
    ofstream file("C:/-N-CSLT/data/products.txt");
    for (int i = 0; i < count; i++) {
        file << products[i].id << "|"
             << products[i].name << "|"
             << products[i].category << "|"
             << products[i].price << "\n";
    }
    file.close();
}

// ================= CUSTOMER =================
    void loadCustomers(Customer*& customers, int& count) {
    ifstream file("C:/-N-CSLT/data/customers.txt");
    count = 0;
    string line;

    while (getline(file, line)) count++;

    file.clear();
    file.seekg(0);

    customers = new Customer[count];
    int i = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, customers[i].id, '|');
        getline(ss, customers[i].name);
        i++;
    }
    file.close();
}

void saveCustomers(Customer* customers, int count) {
    ofstream file("C:/-N-CSLT/data/customers.txt");
    for (int i = 0; i < count; i++) {
        file << customers[i].id << " "
             << customers[i].name << " "
             << customers[i].totalOrders << endl;
    }
    file.close();
}

// ================= STAFF =================
    void loadStaffs(Staff*& staffs, int& count) {
    ifstream file("C:/-N-CSLT/data/staffs.txt");
    count = 0;
    string line;

    while (getline(file, line)) count++;

    file.clear();
    file.seekg(0);

    staffs = new Staff[count];
    int i = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, staffs[i].id, '|');
        getline(ss, staffs[i].name);
        i++;
    }
    file.close();

void saveStaffs(Staff* staffs, int count) {
    ofstream file("C:/-N-CSLT/data/staffs.txt");
    for (int i = 0; i < count; i++) {
        file << staffs[i].id << " "
             << staffs[i].name << " "
             << staffs[i].totalOrders << endl;
    }
    file.close();
}
