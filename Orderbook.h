//
// Created by faraaz on 19/08/2026.
//

#ifndef LIMITORDERBOOK_ORDERBOOK_H
#define LIMITORDERBOOK_ORDERBOOK_H

#include "Order.h"
#include <map>
#include <numeric>
#include <unordered_map>

#include "OrderbookLevelInfos.h"
#include "OrderModify.h"
#include "Trade.h"

class Orderbook {

private:
    struct OrderEntry {
        OrderPointer order_{ nullptr };
        OrderPointers::iterator location_;
    };

    std::map<Price, OrderPointers, std::greater<Price>> bids_;
    std::map<Price, OrderPointers, std::less<Price>> asks_;
    std::unordered_map<OrderId, OrderEntry> orders_;

    bool CanMatch(Side side, Price price) const;

    Trades MatchOrders();

public:
    Trades AddOrder(OrderPointer order);

    void CancelOrder(OrderId orderId);

    Trades MatchOrder(OrderModify order);

    std::size_t Size() const { return orders_.size(); }

    OrderbookLevelInfos GetOrderInfos() const;

};

#endif //LIMITORDERBOOK_ORDERBOOK_H
