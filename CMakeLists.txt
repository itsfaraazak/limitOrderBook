cmake_minimum_required(VERSION 3.30)
project(limitOrderBook)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(limitOrderBook main.cpp
        TradeInfo.h
        Usings.h
        Order.h
        OrderModify.h
        Trade.h
        Orderbook.h
        OrderType.h
        Side.h
        LevelInfo.h
        OrderbookLevelInfos.h
        Orderbook.cpp
        Constants.h)

add_subdirectory(tests)