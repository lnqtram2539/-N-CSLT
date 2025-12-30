#include "models/Product.h"
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

    cin.ignore(); // ⚠️ CỰC KỲ QUAN TRỌNG

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
