//
// Created by faraaz on 19/08/2026.
//

#ifndef LIMITORDERBOOK_TRADE_H
#define LIMITORDERBOOK_TRADE_H

#include "TradeInfo.h"

class Trade {
private:
    TradeInfo bidTrade_;
    TradeInfo askTrade_;

public:
    Trade(const TradeInfo& bidTrade, const TradeInfo& askTrade)
        : bidTrade_{ bidTrade }
    , askTrade_{ askTrade }
    { }

    const TradeInfo& GetBidTrade() { return bidTrade_; }
    const TradeInfo& GetAskTrade() { return askTrade_; }
};

using Trades = std::vector<Trade>;

#endif //LIMITORDERBOOK_TRADE_H
