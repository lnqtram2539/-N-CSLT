# -N-CSLT
# ☕ Cafe Management System (C++ Console Application)

## 📌 Giới thiệu
Dự án **Cafe Management System** là chương trình quản lý cửa hàng cafe được xây dựng bằng **C++ (console application)**.  
Mục tiêu của dự án là mô phỏng các chức năng quản lý cơ bản trong một cửa hàng cafe như:
- Quản lý sản phẩm, khách hàng, nhân viên
- Quản lý hóa đơn và tồn kho
- Thống kê, báo cáo doanh thu và hiệu suất kinh doanh

Dự án được thực hiện theo hình thức **làm việc nhóm (4 người)**, chia theo **3 nhóm chức năng chính**, phù hợp với sinh viên năm nhất.

---

## 🛠 Công nghệ sử dụng
- Ngôn ngữ: **C++**
- Môi trường: Console (Terminal)
- Lưu trữ dữ liệu: File text (`.txt`)
- Công cụ: GitHub, VS Code / CodeBlocks

---

## 📂 Cấu trúc thư mục
CafeManagement/
│
├── main.cpp // Menu chính & điều hướng chương trình
│
├── models/ // Các lớp/struct dữ liệu
│ ├── Product.h / Product.cpp
│ ├── Bill.h / Bill.cpp
│ ├── Customer.h / Customer.cpp
│ └── Staff.h / Staff.cpp
│
├── core/ // Chức năng dùng chung
│ ├── FileHandler.h / FileHandler.cpp
│ └── Utils.h / Utils.cpp
│
├── reports/ // Các nhóm báo cáo
│ ├── RevenueReport.h / RevenueReport.cpp
│ ├── ProductReport.h / ProductReport.cpp
│ ├── InventoryReport.h / InventoryReport.cpp
│ ├── CustomerReport.h / CustomerReport.cpp
│ ├── StaffReport.h / StaffReport.cpp
│ └── ChannelReport.h / ChannelReport.cpp
│
└── data/ // Dữ liệu mẫu
├── products.txt
├── bills.txt
├── bill_items.txt
├── customers.txt
└── staffs.txt


---

## 📌 Chức năng chính

### 1️⃣ Nhóm 1 – Quản lý dữ liệu cơ sở
- Quản lý sản phẩm (thêm / sửa / xóa)
- Quản lý khách hàng
- Quản lý nhân viên
- Đọc / ghi dữ liệu từ file

### 2️⃣ Nhóm 2 – Dữ liệu phát sinh
- Quản lý hóa đơn bán hàng
- Tính tổng tiền hóa đơn
- Cập nhật tồn kho khi bán
- Xử lý ngày / tuần / tháng

### 3️⃣ Nhóm 3 – Báo cáo & thống kê
- Báo cáo doanh thu theo ngày / tuần / tháng
- Báo cáo theo chi nhánh
- Top sản phẩm bán chạy
- Báo cáo tồn kho & cảnh báo
- Báo cáo khách hàng (mới / quay lại)
- Báo cáo nhân viên
- Doanh thu theo kênh bán (offline / app / grab)

---

## 👥 Phân công nhóm (4 người)

| Thành viên | Nhóm | Phụ trách chính |
|------------|------|-----------------|
| SV1 | Nhóm 1 | Product, Customer, Staff, FileHandler |
| SV2 | Nhóm 2 | Bill, Utils, xử lý dữ liệu phát sinh |
| SV3 | Nhóm 3A | RevenueReport, ProductReport, ChannelReport |
| SV4 | Nhóm 3B | InventoryReport, CustomerReport, StaffReport, báo cáo |

---

## ▶️ Cách chạy chương trình
1. Clone repository:
```bash
git clone <link-repo>
