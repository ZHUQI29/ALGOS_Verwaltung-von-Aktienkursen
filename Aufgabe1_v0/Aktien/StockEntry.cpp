#include "StockEntry.hpp"

StockEntry::StockEntry() {
    this->date = "";
    this->open = 0.0;
    this->high = 0.0;
    this->low = 0.0;
    this->close = 0.0;
    this->adj_close = 0.0;
    this->volume = 0;
}

StockEntry::StockEntry(std::string date, float open, float high, float low, float close, float adj_close, int volume) {
    this->date = date;
    this->open = open;
    this->high = high;
    this->low = low;
    this->close = close;
    this->adj_close = adj_close;
    this->volume = volume;
}