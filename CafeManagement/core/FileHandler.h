#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "../models/Product.h"
#include "../models/Customer.h"
#include "../models/Staff.h"
<<<<<<< HEAD

// ================= PRODUCT =================
void loadProducts(Product*& products, int& count);
void saveProducts(Product* products, int count);

// ================= CUSTOMER =================
void loadCustomers(Customer*& customers, int& count);
void saveCustomers(Customer* customers, int count);

// ================= STAFF =================
void loadStaffs(Staff*& staffs, int& count);
void saveStaffs(Staff* staffs, int count);

=======
#include "../models/Bill.h"

// PRODUCT
void loadProducts(Product*& products, int& count);
void saveProducts(Product* products, int count);

// CUSTOMER
void loadCustomers(Customer*& customers, int& count);
void saveCustomers(Customer* customers, int count);

// STAFF
void loadStaffs(Staff*& staffs, int& count);
void saveStaffs(Staff* staffs, int count);

// BILL
void loadBills(Bill*& bills, int& count);
void saveBills(Bill* bills, int count);

>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76
#endif
