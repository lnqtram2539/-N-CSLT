#include "FileHandler.h"
#include <fstream>

// ================= PRODUCT =================
Product* loadProducts(int& count) {
    count = 0;
    Product* products = nullptr;
    ifstream file("data/products.txt");

    Product temp;
    while (file >> temp.id >> temp.name >> temp.category >> temp.price >> temp.stock) {
        Product* newArr = new Product[count + 1];
        for (int i = 0; i < count; i++) {
            newArr[i] = products[i];
        }
        newArr[count] = temp;
        delete[] products;
        products = newArr;
        count++;
    }

    file.close();
    return products;
}

void saveProducts(Product* products, int count) {
    ofstream file("data/products.txt");
    for (int i = 0; i < count; i++) {
        file << products[i].id << " "
             << products[i].name << " "
             << products[i].category << " "
             << products[i].price << " "
             << products[i].stock << endl;
    }
    file.close();
}

// ================= CUSTOMER =================
Customer* loadCustomers(int& count) {
    count = 0;
    Customer* customers = nullptr;
    ifstream file("data/customers.txt");

    Customer temp;
    while (file >> temp.id >> temp.name >> temp.totalOrders) {
        Customer* newArr = new Customer[count + 1];
        for (int i = 0; i < count; i++) {
            newArr[i] = customers[i];
        }
        newArr[count] = temp;
        delete[] customers;
        customers = newArr;
        count++;
    }

    file.close();
    return customers;
}

void saveCustomers(Customer* customers, int count) {
    ofstream file("data/customers.txt");
    for (int i = 0; i < count; i++) {
        file << customers[i].id << " "
             << customers[i].name << " "
             << customers[i].totalOrders << endl;
    }
    file.close();
}

// ================= STAFF =================
Staff* loadStaffs(int& count) {
    count = 0;
    Staff* staffs = nullptr;
    ifstream file("data/staffs.txt");

    Staff temp;
    while (file >> temp.id >> temp.name >> temp.totalOrders) {
        Staff* newArr = new Staff[count + 1];
        for (int i = 0; i < count; i++) {
            newArr[i] = staffs[i];
        }
        newArr[count] = temp;
        delete[] staffs;
        staffs = newArr;
        count++;
    }

    file.close();
    return staffs;
}

void saveStaffs(Staff* staffs, int count) {
    ofstream file("data/staffs.txt");
    for (int i = 0; i < count; i++) {
        file << staffs[i].id << " "
             << staffs[i].name << " "
             << staffs[i].totalOrders << endl;
    }
    file.close();
}
