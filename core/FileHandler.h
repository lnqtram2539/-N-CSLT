#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "../models/Product.h"
#include "../models/Customer.h"
#include "../models/Staff.h"

// Product
Product* loadProducts(int& count);
void saveProducts(Product* products, int count);

// Customer
Customer* loadCustomers(int& count);
void saveCustomers(Customer* customers, int count);

// Staff
Staff* loadStaffs(int& count);
void saveStaffs(Staff* staffs, int count);

#endif
