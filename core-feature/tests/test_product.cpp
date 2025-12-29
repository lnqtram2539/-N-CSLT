#include <iostream>
#include "../models/Product.h"

int main() {
    Product* p = new Product("P01", "Cafe Sua", 20000);

    p->print();
    p->setPrice(25000);

    std::cout << "After update:\n";
    p->print();

    delete p;
    return 0;
}
