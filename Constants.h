//
// Created by faraaz on 19/08/2026.
//

#ifndef LIMITORDERBOOK_CONSTANTS_H
#define LIMITORDERBOOK_CONSTANTS_H

#include <limits>
#include "Usings.h"

struct Constants {
    static const Price InvalidPrice = std::numeric_limits<Price>::quiet_NaN();
};

#endif //LIMITORDERBOOK_CONSTANTS_H
