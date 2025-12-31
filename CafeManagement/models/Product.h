<<<<<<<< HEAD:CafeManagement/models/Product.h
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
========
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

// Quản lý sản phẩm (dùng con trỏ)
void addProduct(Product*& products, int& count);
void removeProduct(Product*& products, int& count);

#endif
>>>>>>>> 45793faf0839d715f82e4b0f6e5cc65dc2aa4e76:models/Product.h
