#include "ReportHandler.h"
#include <iostream>
#include <fstream>

using namespace std;

// ================= DOANH THU THEO NGAY =================
void reportRevenueByDate(Bill* bills, int billCount) {
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

    cout << "Doanh thu ngay " << date << ": " << total << endl;
}

// ================= DOANH THU THEO THANG =================
void reportRevenueByMonth(Bill* bills, int billCount) {
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

    cout << "Doanh thu thang " << month << ": " << total << endl;
}

// ================= TONG HOA DON THEO NGAY =================
void reportBillCountByDate(Bill* bills, int billCount) {
    string date;
    cin.ignore();
    cout << "Nhap ngay (dd/mm/yyyy): ";
    getline(cin, date);

    int count = 0;
    for (int i = 0; i < billCount; i++) {
        if (bills[i].date == date) {
            count++;
        }
    }

    cout << "Tong so hoa don ngay " << date << ": " << count << endl;
}

// ================= SAN PHAM BAN CHAY / IT =================
void reportBestWorstProduct(Bill* bills, int billCount, Product* products, int productCount) {
    int* sold = new int[productCount]{0};

    for (int i = 0; i < billCount; i++) {
        for (int j = 0; j < productCount; j++) {
            if (bills[i].productId == products[j].id) {
                sold[j] += bills[i].quantity;
            }
        }
    }

    int maxIdx = 0, minIdx = 0;
    for (int i = 1; i < productCount; i++) {
        if (sold[i] > sold[maxIdx]) maxIdx = i;
        if (sold[i] < sold[minIdx]) minIdx = i;
    }

    cout << "San pham ban chay nhat: " << products[maxIdx].name
         << " (" << sold[maxIdx] << ")\n";
    cout << "San pham ban it nhat: " << products[minIdx].name
         << " (" << sold[minIdx] << ")\n";

    delete[] sold;
}

// ================= DOANH THU THEO DANH MUC =================
void reportRevenueByCategory(Bill* bills, int billCount, Product* products, int productCount) {
    cout << "Doanh thu theo danh muc:\n";

    for (int i = 0; i < productCount; i++) {
        double total = 0;
        for (int j = 0; j < billCount; j++) {
            if (bills[j].productId == products[i].id) {
                total += bills[j].totalAmount;
            }
        }
        cout << products[i].category << ": " << total << endl;
    }
}

// ================= GIO CAO DIEM =================
void reportPeakHour(Bill* bills, int billCount) {
    int hourCount[24] = {0};

    for (int i = 0; i < billCount; i++) {
        // date format: dd/mm/yyyy hh
        int hour = stoi(bills[i].date.substr(11, 2));
        hourCount[hour]++;
    }

    int peak = 0;
    for (int i = 1; i < 24; i++) {
        if (hourCount[i] > hourCount[peak]) peak = i;
    }

    cout << "Gio cao diem ban hang: " << peak << ":00\n";
}

// ================= TIM KIEM HOA DON =================
void searchBillById(Bill* bills, int billCount) {
    string id;
    cin.ignore();
    cout << "Nhap ma hoa don: ";
    getline(cin, id);

    for (int i = 0; i < billCount; i++) {
        if (bills[i].billId == id) {
            cout << bills[i].billId << " | "
                 << bills[i].productId << " | "
                 << bills[i].quantity << " | "
                 << bills[i].totalAmount << " | "
                 << bills[i].date << endl;
            return;
        }
    }
    cout << "Khong tim thay hoa don!\n";
}

void searchBillByDate(Bill* bills, int billCount) {
    string date;
    cin.ignore();
    cout << "Nhap ngay (dd/mm/yyyy): ";
    getline(cin, date);

    for (int i = 0; i < billCount; i++) {
        if (bills[i].date.find(date) != string::npos) {
            cout << bills[i].billId << " | "
                 << bills[i].totalAmount << " | "
                 << bills[i].date << endl;
        }
    }
}

// ================= XUAT BAO CAO =================
void exportReport(Bill* bills, int billCount, Product* products, int productCount) {
    ofstream file("data/report.txt");

    file << "===== BAO CAO DOANH THU =====\n";
    for (int i = 0; i < billCount; i++) {
        file << bills[i].billId << " | "
             << bills[i].productId << " | "
             << bills[i].quantity << " | "
             << bills[i].totalAmount << " | "
             << bills[i].date << "\n";
    }

    file.close();
    cout << "Xuat bao cao thanh cong (report.txt)\n";
}
