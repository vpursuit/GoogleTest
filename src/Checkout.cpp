//
// Created by Trebing, Peter on 05.09.19.
//

#include "Checkout.h"

Checkout::Checkout() : totals(0) {}

Checkout::~Checkout() {}

void Checkout::addItemPrice(std::string item, int price) {
    prices[item] = price;
}

void Checkout::addItem(std::string item) {
    std::map<std::string, int>::iterator it = prices.find(item);
    if (it == prices.end()) {
        throw std::invalid_argument("Invalid item with no price.");
    }
    items[item]++;
}

int Checkout::calculateTotal() {
    totals = 0;

    for (auto i : items) {
        std::string item = i.first;
        int itemCount = i.second;
        calculateItem(item, itemCount);
    }

    return totals;
}

void Checkout::addDiscount(std::string item, int numberOfItems, int discountPrice) {
    Discount discount;
    discount.numberOfItems = numberOfItems;
    discount.discountPrice = discountPrice;
    discounts[item] = discount;
}

void Checkout::calculateItem(std::string item, int itemCount) {
    auto discountIterator = discounts.find(item);
    if (discountIterator != discounts.end()) {
        Discount discount = discountIterator->second;
        calculateDiscount(item, itemCount, discount);
    } else {
        totals += itemCount * prices[item];
    }
}

void Checkout::calculateDiscount(std::string item, int itemCount, Discount discount) {
    if (itemCount >= discount.numberOfItems) {
        int numberOfDiscountItems = itemCount / discount.numberOfItems;
        totals += numberOfDiscountItems * discount.discountPrice;
        int remainingItems = itemCount % discount.numberOfItems;
        totals += remainingItems * prices[item];
    } else {
        totals += itemCount * prices[item];
    }
}
