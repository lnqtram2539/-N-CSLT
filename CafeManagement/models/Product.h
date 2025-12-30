#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

struct Product {
    string id;
    string name;
    string category;
    double price;
    int stock;
};

// Quản lý sản phẩm
void addProduct(Product*& products, int& count);
void removeProduct(Product*& products, int& count);

#endif // PRODUCT_H
