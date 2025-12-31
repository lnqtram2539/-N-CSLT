<<<<<<<< HEAD:CafeManagement/models/Product.cpp
#include "Product.h"
#include <iostream>

using namespace std;

void addProduct(Product*& products, int& count) {
    Product p;

    cout << "Nhap ma san pham: ";
    cin >> p.id;

    for (int i = 0; i < count; i++) {
        if (products[i].id == p.id) {
            cout << "Ma san pham da ton tai!\n";
            return;
        }
    }

    cin.ignore(); // 🔴 RẤT QUAN TRỌNG

    cout << "Nhap ten san pham: ";
    getline(cin, p.name);   // có thể nhập "Ca phe den"

    cout << "Nhap danh muc: ";
    getline(cin, p.category); // ví dụ: "Do uong nong"

    cout << "Nhap gia: ";
    cin >> p.price;

    cout << "Nhap so luong ton kho: ";
    cin >> p.stock;

    Product* newArr = new Product[count + 1];
    for (int i = 0; i < count; i++) {
        newArr[i] = products[i];
    }

    newArr[count] = p;

    delete[] products;
    products = newArr;
    count++;

    cout << "Them san pham thanh cong!\n";
}


void removeProduct(Product*& products, int& count) {
    if (count == 0) {
        cout << "Danh sach san pham rong!\n";
        return;
    }

    string id;
    cout << "Nhap ma san pham can xoa: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Khong tim thay san pham!\n";
        return;
    }

    Product* newArr = new Product[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            newArr[j++] = products[i];
        }
    }

    delete[] products;
    products = newArr;
    count--;

    cout << "Xoa san pham thanh cong!\n";
}
========
#include "Product.h"
#include <iostream>

using namespace std;

void addProduct(Product*& products, int& count) {
    Product p;

    cout << "Nhap ma san pham: ";
    cin >> p.id;

    for (int i = 0; i < count; i++) {
        if (products[i].id == p.id) {
            cout << "Ma san pham da ton tai!\n";
            return;
        }
    }

    cin.ignore(); // 🔴 RẤT QUAN TRỌNG

    cout << "Nhap ten san pham: ";
    getline(cin, p.name);   // có thể nhập "Ca phe den"

    cout << "Nhap danh muc: ";
    getline(cin, p.category); // ví dụ: "Do uong nong"

    cout << "Nhap gia: ";
    cin >> p.price;

    cout << "Nhap so luong ton kho: ";
    cin >> p.stock;

    Product* newArr = new Product[count + 1];
    for (int i = 0; i < count; i++) {
        newArr[i] = products[i];
    }

    newArr[count] = p;

    delete[] products;
    products = newArr;
    count++;

    cout << "Them san pham thanh cong!\n";
}


void removeProduct(Product*& products, int& count) {
    string id;
    cout << "Nhap ma san pham can xoa: ";
    cin >> id;

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (products[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Khong tim thay san pham!\n";
        return;
    }

    Product* newArr = new Product[count - 1];
    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            newArr[j++] = products[i];
        }
    }

    delete[] products;
    products = newArr;
    count--;

    cout << "Xoa san pham thanh cong!\n";
}
>>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76:models/Product.cpp
