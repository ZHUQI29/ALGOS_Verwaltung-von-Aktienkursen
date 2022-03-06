#ifndef AKTIEN_STOCKENTRY_HPP
#define AKTIEN_STOCKENTRY_HPP

#include <ctime>
#include <string>

class StockEntry {
public:
    StockEntry();
    StockEntry(std::string date, float open, float high, float low, float close, float adj_close, int volume);
    ~StockEntry();
    std::string date;
    float open;
    float high;
    float low;
    float close;
    float adj_close;
    int volume;


private:

};


#endif //AKTIEN_STOCKENTRY_HPP
