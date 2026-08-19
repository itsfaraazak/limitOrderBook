//
// Created by faraaz on 19/08/2026.
//

#ifndef LIMITORDERBOOK_TRADEINFO_H
#define LIMITORDERBOOK_TRADEINFO_H

#include "Usings.h"

struct TradeInfo {
    OrderId orderId_;
    Price price_;
    Quantity quantity_;
};


#endif //LIMITORDERBOOK_TRADEINFO_H
