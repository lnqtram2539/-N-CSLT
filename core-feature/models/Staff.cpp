#include "Staff.h"
#include <iostream>
using namespace std;

void addStaff(Staff*& staffs, int& count) {
    Staff s;

    cout << "Nhap ma nhan vien: ";
    cin >> s.id;

    for (int i = 0; i < count; i++) {
        if (staffs[i].id == s.id) {
            cout << "Ma nhan vien da ton tai!\n";
            return;
        }
    }

    cin.ignore(); // ⚠️ RẤT QUAN TRỌNG

    cout << "Nhap ten nhan vien: ";
    getline(cin, s.name);

    s.totalOrders = 0;

    Staff* newArr = new Staff[count + 1];
    for (int i = 0; i < count; i++) {
        newArr[i] = staffs[i];
    }

    newArr[count] = s;

    delete[] staffs;
    staffs = newArr;
    count++;

    cout << "Them nhan vien thanh cong!\n";
}
