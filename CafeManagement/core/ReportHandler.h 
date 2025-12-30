#ifndef REPORTHANDLER_H
#define REPORTHANDLER_H

#include "../models/Bill.h"
#include "../models/Product.h"

using namespace std;

// 1. Doanh thu theo ngày / tháng
void reportRevenueByDate(Bill* bills, int billCount);
void reportRevenueByMonth(Bill* bills, int billCount);

// 2. Tổng số hóa đơn theo ngày
void reportBillCountByDate(Bill* bills, int billCount);

// 3. Sản phẩm bán chạy nhất / ít nhất
void reportBestWorstProduct(Bill* bills, int billCount, Product* products, int productCount);

// 4. Doanh thu theo danh mục
void reportRevenueByCategory(Bill* bills, int billCount, Product* products, int productCount);

// 5. Giờ cao điểm bán hàng
void reportPeakHour(Bill* bills, int billCount);

// 6. Tìm kiếm hóa đơn
void searchBillById(Bill* bills, int billCount);
void searchBillByDate(Bill* bills, int billCount);

// 7. Xuất báo cáo ra file
void exportReport(Bill* bills, int billCount, Product* products, int productCount);

#endif
