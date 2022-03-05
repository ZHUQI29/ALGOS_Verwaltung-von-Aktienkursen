#ifndef AKTIEN_HOLDER_HPP
#define AKTIEN_HOLDER_HPP

#include <vector>
#include <string>
#include <map>
#include "Stock.hpp"
#include "HashTable.hpp"

using namespace std;

class Holder {
public:
    Holder();
    void addStock(vector<string> strArray, string abbreviation, string name);
    vector<Stock*> stocks;
    vector<string> line(string str);
    Stock* search(string input);
private:
    HashTable* hashTable;
    HashTable* abbrToNameDic;
};


#endif //AKTIEN_HOLDER_HPP
