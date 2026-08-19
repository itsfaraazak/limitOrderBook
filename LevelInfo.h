//
// Created by faraaz on 19/08/2026.
//

#ifndef LIMITORDERBOOK_LEVELINFO_H
#define LIMITORDERBOOK_LEVELINFO_H

#include "Usings.h"

struct LevelInfo {
    Price price_;
    Quantity quantity_;
};


using LevelInfos = std::vector<LevelInfo>;

#endif //LIMITORDERBOOK_LEVELINFO_H
