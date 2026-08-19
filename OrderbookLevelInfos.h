//
// Created by faraaz on 19/08/2026.
//

#ifndef LIMITORDERBOOK_ORDERBOOKLEVELINFOS_H
#define LIMITORDERBOOK_ORDERBOOKLEVELINFOS_H

#include "LevelInfo.h"

class OrderbookLevelInfos {
private:
    LevelInfos bids_;
    LevelInfos asks_;

public:
    OrderbookLevelInfos(const LevelInfos& bids, const LevelInfos& asks)
        : bids_ { bids }
    , asks_ { asks }
    { }

    const LevelInfos& GetBids() const { return bids_; }

    const LevelInfos& GetAsks() const { return asks_; }
};


#endif //LIMITORDERBOOK_ORDERBOOKLEVELINFOS_H
