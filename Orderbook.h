//
// Created by faraaz on 19/08/2026.
//

#ifndef LIMITORDERBOOK_ORDERBOOK_H
#define LIMITORDERBOOK_ORDERBOOK_H

#include <atomic>
#include <condition_variable>

#include "Order.h"
#include <map>
#include <numeric>
#include <thread>
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

    struct LevelData {
        Quantity quantity_{ };
        Quantity count_{ };

        enum class Action {
            Add,
            Remove,
            Match,
        };
    };

    std::unordered_map<Price, LevelData> data_;

    std::map<Price, OrderPointers, std::greater<Price>> bids_;
    std::map<Price, OrderPointers, std::less<Price>> asks_;
    std::unordered_map<OrderId, OrderEntry> orders_;

    mutable std::mutex ordersMutex_;
    std::thread ordersPruneThread_;
    std::condition_variable shutdownConditionVariable_;
    std::atomic<bool> shutdown_{ false };

    bool CanMatch(Side side, Price price) const;

    Trades MatchOrders();


    void CancelOrders(OrderIds orderIds);

    void CancelOrderInternal(OrderId orderId);

    void OnOrderCancelled(OrderPointer order);
    void OnOrderAdded(OrderPointer order);
    void OnOrderMatched(Price price, Quantity quantity, bool isFullyFilled);
    void UpdateLevelData(Price price, Quantity quantity, LevelData::Action action);

    bool CanFullyFill(Side side, Price price, Quantity quantity) const;


public:
    Trades AddOrder(OrderPointer order);

    void CancelOrder(OrderId orderId);


    Trades MatchOrder(OrderModify order);

    std::size_t Size() const { return orders_.size(); }

    OrderbookLevelInfos GetOrderInfos() const;

    Orderbook();
    ~Orderbook();

    void PruneGoodForDayOrders();



};

#endif //LIMITORDERBOOK_ORDERBOOK_H
