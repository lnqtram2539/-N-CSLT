#include "Staff.h"
#include <iostream>

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

    cout << "Nhap ten nhan vien: ";
    cin >> s.name;

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

void removeStaff(Staff*& staffs, int& count) {
    string id;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (staffs[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Khong tim thay nhan vien!\n";
        return;
    }

    Staff* newArr = new Staff[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            newArr[j++] = staffs[i];
        }
    }

    delete[] staffs;
    staffs = newArr;
    count--;

    cout << "Xoa nhan vien thanh cong!\n";
}
