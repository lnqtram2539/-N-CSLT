<<<<<<<< HEAD:CafeManagement/models/Staff.h
#ifndef STAFF_H
#define STAFF_H

#include <string>
using namespace std;

struct Staff {
    string id;
    string name;
    int totalOrders;
};

// Quản lý nhân viên
void addStaff(Staff*& staffs, int& count);
void removeStaff(Staff*& staffs, int& count);

#endif // STAFF_H
========
#ifndef STAFF_H
#define STAFF_H

#include <string>
using namespace std;

struct Staff {
    string id;
    string name;
    int totalOrders;
};

// Quản lý nhân viên
void addStaff(Staff*& staffs, int& count);
void removeStaff(Staff*& staffs, int& count);

#endif
>>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76:models/Staff.h
