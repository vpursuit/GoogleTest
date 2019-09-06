//
// Created by Trebing, Peter on 05.09.19.
//

#ifndef GOOGLETEST_TEST_CHECKOUT_H
#define GOOGLETEST_TEST_CHECKOUT_H

#include <string>
#include <map>

struct Discount {
    int numberOfItems;
    int discountPrice;
};

class Checkout {

public:
    Checkout();

    virtual ~Checkout();

    void addItemPrice(std::string item, int price);

    void addItem(std::string item);

    int calculateTotal();

    void addDiscount(std::string item, int numberOfItems, int discountPrice);

    void calculateItem(std::string item, int itemCount);

    void calculateDiscount(std::string item, int itemCount, Discount discount);

protected:
    std::map<std::string, int> prices;
    std::map<std::string, Discount> discounts;
    std::map<std::string, int> items;
    int totals;
};


#endif //GOOGLETEST_TEST_CHECKOUT_H
