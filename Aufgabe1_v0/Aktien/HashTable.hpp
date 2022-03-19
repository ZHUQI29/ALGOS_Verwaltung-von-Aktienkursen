#ifndef AKTIEN_HASHTABLE_HPP
#define AKTIEN_HASHTABLE_HPP

#include <vector>
#include <string>
#include "globals.hpp"
#include "Stock.hpp"

class HashTable {
public:
    HashTable();
    ~HashTable();
    int hash(std::string word);
    void insert(Stock* stock, string name);
    Stock* search(int index, string abr);
    void del(int index, string abbr);
    vector<Stock*>* getStockFromIndex(int index);

private:
    vector<Stock*> Table[TABLE_SIZE];
};


#endif //AKTIEN_HASHTABLE_HPP
