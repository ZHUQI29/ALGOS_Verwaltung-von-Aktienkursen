#include "Stock.hpp"

Stock::Stock(string abbr, string name, StockEntry **entries) {
    this->abbreviation = abbr;
    this->name = name;
    for (int i = 0; i < 30; ++i) {
        this->entries[i] = entries[i];
    }
}

Stock::Stock(string abbr, string name) {
    this->abbreviation = abbr;
    this->name = name;
}