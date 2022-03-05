#include "Stock.hpp"

Stock::Stock(string abbr, StockEntry **entries) {
    this->abbreviation = abbr;
    for (int i = 0; i < 30; ++i) {
        this->entries[i] = entries[i];
    }
}