#include "Product.h"
#include <iostream>

void addProduct(Product*& products, int& count) {
    Product newProduct;

    cout << "Nhap ma san pham: ";
    cin >> newProduct.id;

    // Kiểm tra trùng ID
    for (int i = 0; i < count; i++) {
        if (products[i].id == newProduct.id) {
            cout << "Ma san pham da ton tai!\n";
            return;
        }
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

    Product* newArray = new Product[count - 1];

    for (int i = 0, j = 0; i < count; i++) {
        if (i != index) {
            newArray[j++] = products[i];
        }
    }

    delete[] products;
    products = newArray;
    count--;

    cout << "Xoa san pham thanh cong!\n";
}


    cout << "Nhap ten san pham: ";
    cin >> newProduct.name;

    cout << "Nhap danh muc: ";
    cin >> newProduct.category;

    cout << "Nhap gia: ";
    cin >> newProduct.price;

    cout << "Nhap so luong ton kho: ";
    cin >> newProduct.stock;

    // Tạo mảng mới lớn hơn
    Product* newArray = new Product[count + 1];

    for (int i = 0; i < count; i++) {
        newArray[i] = products[i];
    }

    newArray[count] = newProduct;

    delete[] products;
    products = newArray;
    count++;

    cout << "Them san pham thanh cong!\n";
}
