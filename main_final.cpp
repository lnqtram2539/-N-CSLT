#include <iostream>

// File load/save
#include "core/FileHandler.h"

// Nhóm 2 – Đơn hàng
#include "core/BillHandler.h"

// Nhóm 3 – Báo cáo
#include "core/ReportHandler.h"

using namespace std;

// ================= MENU NHOM 1 =================
void menuGroup1(Product*& products, int& productCount,
                Customer*& customers, int& customerCount,
                Staff*& staffs, int& staffCount) {
    int choice;
    do {
        cout << "\n===== NHOM 1: QUAN LY CO BAN =====\n";
        cout << "1. Quan ly san pham\n";
        cout << "2. Quan ly khach hang\n";
        cout << "3. Quan ly nhan vien\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            productMenu(products, productCount);
            saveProducts(products, productCount);
            break;
        case 2:
            customerMenu(customers, customerCount);
            saveCustomers(customers, customerCount);
            break;
        case 3:
            staffMenu(staffs, staffCount);
            saveStaffs(staffs, staffCount);
            break;
        }
    } while (choice != 0);
}

// ================= MENU NHOM 2 =================
void menuGroup2(Bill*& bills, int& billCount,
                Product*& products, int& productCount) {
    int choice;
    do {
        cout << "\n===== NHOM 2: DON HANG =====\n";
        cout << "1. Tao don hang\n";
        cout << "2. Hien thi danh sach don hang\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            createBill(bills, billCount, products, productCount);
            saveBills(bills, billCount);
            saveProducts(products, productCount);
            break;
        case 2:
            showBills(bills, billCount);
            break;
        }
    } while (choice != 0);
}

// ================= MENU NHOM 3 =================
void menuGroup3(Bill* bills, int billCount,
                Product* products, int productCount) {
    int choice;
    do {
        cout << "\n===== NHOM 3: BAO CAO & THONG KE =====\n";
        cout << "1. Doanh thu theo ngay\n";
        cout << "2. Doanh thu theo thang\n";
        cout << "3. Tong so hoa don theo ngay\n";
        cout << "4. San pham ban chay / it\n";
        cout << "5. Doanh thu theo danh muc\n";
        cout << "6. Gio cao diem ban hang\n";
        cout << "7. Tim hoa don theo ID\n";
        cout << "8. Tim hoa don theo ngay\n";
        cout << "9. Xuat bao cao ra file\n";
        cout << "0. Quay lai\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            reportRevenueByDate(bills, billCount);
            break;
        case 2:
            reportRevenueByMonth(bills, billCount);
            break;
        case 3:
            reportBillCountByDate(bills, billCount);
            break;
        case 4:
            reportBestWorstProduct(bills, billCount, products, productCount);
            break;
        case 5:
            reportRevenueByCategory(bills, billCount, products, productCount);
            break;
        case 6:
            reportPeakHour(bills, billCount);
            break;
        case 7:
            searchBillById(bills, billCount);
            break;
        case 8:
            searchBillByDate(bills, billCount);
            break;
        case 9:
            exportReport(bills, billCount, products, productCount);
            break;
        }
    } while (choice != 0);
}

// ================= MAIN =================
int main() {
    // Load dữ liệu
    int productCount = 0, customerCount = 0, staffCount = 0, billCount = 0;

    Product* products = loadProducts(productCount);
    Customer* customers = loadCustomers(customerCount);
    Staff* staffs = loadStaffs(staffCount);
    Bill* bills = loadBills(billCount);

    int choice;
    do {
        cout << "\n========== CAFE MANAGEMENT ==========\n";
        cout << "1. Nhom 1 - Quan ly co ban\n";
        cout << "2. Nhom 2 - Don hang\n";
        cout << "3. Nhom 3 - Bao cao\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            menuGroup1(products, productCount, customers, customerCount, staffs, staffCount);
            break;
        case 2:
            menuGroup2(bills, billCount, products, productCount);
            break;
        case 3:
            menuGroup3(bills, billCount, products, productCount);
            break;
        case 0:
            cout << "Thoat chuong trinh...\n";
            break;
        default:
            cout << "Lua chon khong hop le!\n";
        }
    } while (choice != 0);

    // Giải phóng bộ nhớ
    delete[] products;
    delete[] customers;
    delete[] staffs;
    delete[] bills;

    return 0;
}
