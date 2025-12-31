#include <iostream>
#include "core/FileHandler.h"
#include "models/Product.h"
#include "models/Customer.h"
#include "models/Staff.h"
#include "models/Bill.h"

using namespace std;

/* ================= MENU SAN PHAM ================= */
void productMenu(Product*& products, int& productCount) {
    int choice;
    do {
        cout << "\n===== QUAN LY SAN PHAM =====\n";
        cout << "1. Hien thi danh sach\n";
        cout << "2. Them san pham\n";
        cout << "3. Xoa san pham\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (productCount == 0) {
                cout << "Danh sach san pham rong!\n";
            } else {
                for (int i = 0; i < productCount; i++) {
                    cout << products[i].id << " | "
                         << products[i].name << " | "
                         << products[i].category << " | "
                         << products[i].price << " | "
                         << products[i].stock << endl;
                }
            }
            break;
        case 2:
            addProduct(products, productCount);
            saveProducts(products, productCount);
            break;
        case 3:
            removeProduct(products, productCount);
            saveProducts(products, productCount);
            break;
        }
    } while (choice != 0);
}

/* ================= MENU KHACH HANG ================= */
void customerMenu(Customer*& customers, int& customerCount) {
    int choice;
    do {
        cout << "\n===== QUAN LY KHACH HANG =====\n";
        cout << "1. Hien thi danh sach\n";
        cout << "2. Them khach hang\n";
        cout << "3. Xoa khach hang\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (customerCount == 0) {
                cout << "Danh sach khach hang rong!\n";
            } else {
                for (int i = 0; i < customerCount; i++) {
                    cout << customers[i].id << " | "
                         << customers[i].name << " | "
                         << customers[i].totalOrders << endl;
                }
            }
            break;
        case 2:
            addCustomer(customers, customerCount);
            saveCustomers(customers, customerCount);
            break;
        case 3:
            removeCustomer(customers, customerCount);
            saveCustomers(customers, customerCount);
            break;
        }
    } while (choice != 0);
}

/* ================= MENU NHAN VIEN ================= */
void staffMenu(Staff*& staffs, int& staffCount) {
    int choice;
    do {
        cout << "\n===== QUAN LY NHAN VIEN =====\n";
        cout << "1. Hien thi danh sach\n";
        cout << "2. Them nhan vien\n";
        cout << "3. Xoa nhan vien\n";
        cout << "0. Quay lai\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (staffCount == 0) {
                cout << "Danh sach nhan vien rong!\n";
            } else {
                for (int i = 0; i < staffCount; i++) {
                    cout << staffs[i].id << " | "
                         << staffs[i].name << " | "
                         << staffs[i].totalOrders << endl;
                }
            }
            break;
        case 2:
            addStaff(staffs, staffCount);
            saveStaffs(staffs, staffCount);
            break;
        case 3:
            removeStaff(staffs, staffCount);
            saveStaffs(staffs, staffCount);
            break;
        }
    } while (choice != 0);
}

/* ================= MENU BAO CAO (NHOM 3) ================= */
void reportMenu(Bill* bills, int billCount) {
    double totalRevenue = 0;

    for (int i = 0; i < billCount; i++) {
        totalRevenue += bills[i].totalPrice;
    }

    cout << "\n===== BAO CAO DOANH THU =====\n";
    cout << "Tong so hoa don: " << billCount << endl;
    cout << "Tong doanh thu: " << totalRevenue << " VND\n";
}

/* ================= MAIN ================= */
int main() {
    Product* products = nullptr;
    Customer* customers = nullptr;
    Staff* staffs = nullptr;
    Bill* bills = nullptr;

    int productCount = 0;
    int customerCount = 0;
    int staffCount = 0;
    int billCount = 0;

    // Load du lieu tu file
    loadProducts(products, productCount);
    loadCustomers(customers, customerCount);
    loadStaffs(staffs, staffCount);
    loadBills(bills, billCount);

    int choice;
    do {
        cout << "\n========== CAFE MANAGEMENT ==========\n";
        cout << "1. Quan ly san pham\n";
        cout << "2. Quan ly khach hang\n";
        cout << "3. Quan ly nhan vien\n";
        cout << "4. Bao cao thong ke\n";
        cout << "0. Thoat\n";
        cout << "Lua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            productMenu(products, productCount);
            break;
        case 2:
            customerMenu(customers, customerCount);
            break;
        case 3:
            staffMenu(staffs, staffCount);
            break;
        case 4:
            reportMenu(bills, billCount);
            break;
        case 0:
            cout << "Thoat chuong trinh!\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    // Giai phong bo nho
    delete[] products;
    delete[] customers;
    delete[] staffs;
    delete[] bills;

    return 0;
}
