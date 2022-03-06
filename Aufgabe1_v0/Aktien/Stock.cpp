#include "Stock.hpp"

Stock::Stock(string abbr, string name, StockEntry **entries) {
    this->abbreviation = abbr;
    this->name = name;
    this->entries = new StockEntry*[30]();
    for (int i = 0; i < 30; ++i) {
        this->entries[i] = entries[i];
    }
}

Stock::Stock(string abbr, string name) {
    this->abbreviation = abbr;
    this->name = name;
    this->entries = new StockEntry*[30]();
}

Stock::~Stock() {
    if (entries != nullptr) {
        for (int i = 0; i < 30; ++i) {
            delete entries[i];
        }

        delete[] entries;
    }
}