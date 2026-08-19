cmake_minimum_required(VERSION 3.20)
project(limitOrderBook)
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
        Orderbook.cpp)