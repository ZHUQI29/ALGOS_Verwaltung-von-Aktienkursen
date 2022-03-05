#ifndef AKTIEN_STOCK_HPP
#define AKTIEN_STOCK_HPP


#include "StockEntry.hpp"
#include <string>
using namespace std;

class Stock {
public:
    Stock(string abbr, StockEntry* entries[30]);
    string abbreviation;
    StockEntry* entries[30];

private:

};


#endif //AKTIEN_STOCK_HPP
