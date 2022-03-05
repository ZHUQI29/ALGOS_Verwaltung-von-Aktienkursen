#ifndef AKTIEN_HOLDER_HPP
#define AKTIEN_HOLDER_HPP

#include <vector>
#include <string>
#include "Stock.hpp"
using namespace std;

class Holder {
public:
    Holder();
    void addStock(vector<string> strArray);
    vector<Stock*> stocks;
    void addStock();
    vector<string> line(string str);
private:
};


#endif //AKTIEN_HOLDER_HPP
