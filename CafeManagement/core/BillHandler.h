#ifndef BILLHANDLER_H
#define BILLHANDLER_H

#include "../models/Bill.h"
#include "../models/Product.h"

using namespace std;

// Load / Save
void loadBills(Bill*& bills, int& billCount);
void saveBills(Bill* bills, int billCount);

// Tạo bill
void createBill(
    Bill*& bills, int& billCount,
    Product*& products, int productCount
);

// Thống kê
void revenueByDate(Bill* bills, int billCount);
void revenueByMonth(Bill* bills, int billCount);

#endif // BILLHANDLER_H
