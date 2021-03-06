#include "Stock.hpp"

// Constructs a Stock from given entries
Stock::Stock(string abbr, string name, StockEntry **entries) {
    this->abbreviation = abbr;
    this->name = name;
    this->entries = new StockEntry*[DAYS_TO_SAVE]();
    for (int i = 0; i < DAYS_TO_SAVE; ++i) {
        this->entries[i] = entries[i];
    }
}

// Create a empty Stock
Stock::Stock(string abbr, string name) {
    this->abbreviation = abbr;
    this->name = name;
    this->entries = new StockEntry*[DAYS_TO_SAVE]();
}

// De-Constructor
Stock::~Stock() {
    if (entries != nullptr) {
        for (int i = 0; i < 30; ++i) {
            delete entries[i];
        }

        delete[] entries;
    }
}