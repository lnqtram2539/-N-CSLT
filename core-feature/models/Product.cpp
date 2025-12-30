#include "Product.h"
#include <iostream>
#include <string>

using namespace std;

// ================= ADD PRODUCT =================
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
    cin.ignore();

    cout << "Nhap ten san pham: ";
    getline(cin, p.name);

    cout << "Nhap danh muc: ";
    getline(cin, p.category);

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

// ================= REMOVE PRODUCT =================
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
