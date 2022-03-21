cmake_minimum_required(VERSION 3.21)
project(Aktien)

set(CMAKE_CXX_STANDARD 17)

add_executable(Aktien main.cpp Stock.cpp Stock.hpp StockEntry.cpp StockEntry.hpp Holder.cpp Holder.hpp HashTable.cpp HashTable.hpp globals.hpp SaveAndLoad.cpp SaveAndLoad.hpp)
