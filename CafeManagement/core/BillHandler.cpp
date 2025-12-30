#include "BillHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// ================= LOAD BILLS =================
void loadBills(Bill*& bills, int& billCount) {
    ifstream file("data/bills.txt");
    billCount = 0;
    string line;

    if (!file.is_open()) {
        bills = nullptr;
        return;
    }

    while (getline(file, line)) billCount++;

    file.clear();
    file.seekg(0);

    bills = new Bill[billCount];
    int i = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, bills[i].billId, '|');
        getline(ss, bills[i].productId, '|');
        ss >> bills[i].quantity;
        ss.ignore();
        ss >> bills[i].totalAmount;
        ss.ignore();
        getline(ss, bills[i].date);
        i++;
    }

    file.close();
}

// ================= SAVE BILLS =================
void saveBills(Bill* bills, int billCount) {
    ofstream file("data/bills.txt");

    for (int i = 0; i < billCount; i++) {
        file << bills[i].billId << "|"
             << bills[i].productId << "|"
             << bills[i].quantity << "|"
             << bills[i].totalAmount << "|"
             << bills[i].date << "\n";
    }

    file.close();
}

// ================= CREATE BILL =================
void createBill(
    Bill*& bills, int& billCount,
    Product*& products, int productCount
) {
    Bill b;

    cin.ignore();

    cout << "Nhap ma hoa don: ";
    getline(cin, b.billId);

    cout << "Nhap ma san pham: ";
    getline(cin, b.productId);

    int index = -1;
    for (int i = 0; i < productCount; i++) {
        if (products[i].id == b.productId) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Khong tim thay san pham!\n";
        return;
    }

    cout << "Nhap so luong: ";
    cin >> b.quantity;

    if (b.quantity > products[index].stock) {
        cout << "Khong du ton kho!\n";
        return;
    }

    b.totalAmount = b.quantity * products[index].price;
    products[index].stock -= b.quantity;

    cin.ignore();
    cout << "Nhap ngay (dd/mm/yyyy): ";
    getline(cin, b.date);

    Bill* newArr = new Bill[billCount + 1];
    for (int i = 0; i < billCount; i++) {
        newArr[i] = bills[i];
    }
    newArr[billCount] = b;

    delete[] bills;
    bills = newArr;
    billCount++;

    saveBills(bills, billCount);

    cout << "Tao hoa don thanh cong! Tong tien: "
         << b.totalAmount << endl;
}

// ================= REVENUE BY DATE =================
void revenueByDate(Bill* bills, int billCount) {
    string date;
    cin.ignore();
    cout << "Nhap ngay (dd/mm/yyyy): ";
    getline(cin, date);

    double total = 0;
    for (int i = 0; i < billCount; i++) {
        if (bills[i].date == date) {
            total += bills[i].totalAmount;
        }
    }

    cout << "Tong doanh thu ngay " << date << ": " << total << endl;
}

// ================= REVENUE BY MONTH =================
void revenueByMonth(Bill* bills, int billCount) {
    string month;
    cin.ignore();
    cout << "Nhap thang/nam (mm/yyyy): ";
    getline(cin, month);

    double total = 0;
    for (int i = 0; i < billCount; i++) {
        if (bills[i].date.find(month) != string::npos) {
            total += bills[i].totalAmount;
        }
    }

    cout << "Tong doanh thu thang " << month << ": " << total << endl;
}

