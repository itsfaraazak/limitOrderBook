//
// Created by faraaz on 19/08/2026.
//

#ifndef LIMITORDERBOOK_ORDER_H
#define LIMITORDERBOOK_ORDER_H


#include <list>
#include <exception>
#include <format>
#include <memory>
#include <stdexcept>

#include "Constants.h"
#include "OrderType.h"
#include "Side.h"
#include "Usings.h"

class Order {
private:
    OrderType orderType_;
    OrderId orderId_;
    Side side_;
    Price price_;
    Quantity initialQuantity_;
    Quantity remainingQuantity_;

public:
    Order(OrderType orderType, OrderId orderId, Side side, Price price, Quantity quantity)
        : orderType_{ orderType }
    , orderId_{ orderId }
    , side_{ side }
    , price_{ price }
    , initialQuantity_{ quantity }
    , remainingQuantity_{ quantity }
    { }

    Order(OrderId orderId, Side side, Quantity quantity)
        : Order(OrderType::Market, orderId, side, Constants::InvalidPrice, quantity)
    { }

    OrderId GetOrderId() const { return orderId_; }
    Side GetSide() const { return side_; }
    Price GetPrice() const { return price_; }
    OrderType GetOrderType() const { return orderType_; }
    Quantity GetInitialQuantity() const { return initialQuantity_; }
    Quantity GetRemainingQuantity() const { return remainingQuantity_; }
    Quantity GetFilledQuantity() const { return GetInitialQuantity() - GetRemainingQuantity(); }

    bool IsFilled() const { return GetRemainingQuantity() == 0; }

    void Fill(Quantity quantity) {
        if (quantity > GetRemainingQuantity()) {
            throw std::logic_error("Order (" + std::to_string(GetOrderId()) + ") cannot be filled for more than its remaining quantity.");
        }
        remainingQuantity_ -= quantity;
    }

    void ToGoodTillCancel(Price price) {
        if (GetOrderType() != OrderType::Market) {
            throw std::logic_error("Order " + std::to_string(GetOrderId()) + " cannot have its price adjusted, only market orders can.");
        }
        //if (!std::is_finite(price))
        price_ = price;
        orderType_ = OrderType::GoodTillCancel;
    }
};


using OrderPointer = std::shared_ptr<Order>;
// This is a list for simplicity, but a vector would be more preformant.
using OrderPointers = std::list<OrderPointer>;

#endif //LIMITORDERBOOK_ORDER_H
