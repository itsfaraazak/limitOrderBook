//
// Created by faraaz on 19/08/2026.
//

#ifndef LIMITORDERBOOK_ORDERMODIFY_H
#define LIMITORDERBOOK_ORDERMODIFY_H

#include <memory>

#include "Order.h"

class OrderModify {
private:
    OrderId orderId_;
    Side side_;
    Price price_;
    Quantity quantity_;

public:
    OrderModify(OrderId orderId, Side side, Price price, Quantity quantity)
        : orderId_{ orderId }
    , side_{ side }
    , price_{ price }
    , quantity_{ quantity }
    { }

    OrderId GetOrderId() const { return orderId_; }
    Price GetPrice() const { return price_; }
    Side GetSide() const { return side_; }
    Quantity GetQuantity() const { return quantity_; }

    OrderPointer ToOrderPointer(OrderType type) const {
        return std::make_shared<Order>(type, GetOrderId(), GetSide(), GetPrice(), GetQuantity());
    }
};

#endif //LIMITORDERBOOK_ORDERMODIFY_H
