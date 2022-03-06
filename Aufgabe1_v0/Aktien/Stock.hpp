#ifndef AKTIEN_STOCK_HPP
#define AKTIEN_STOCK_HPP


#include "StockEntry.hpp"
#include <string>
using namespace std;

class Stock {
public:
    Stock(string abbr, string name, StockEntry* entries[30]);
    Stock(string abbr, string name);
    ~Stock();
    string abbreviation;
    string name;
    StockEntry** entries;

private:

};


#endif //AKTIEN_STOCK_HPP
