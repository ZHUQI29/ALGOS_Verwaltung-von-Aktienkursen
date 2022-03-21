#include "HashTable.hpp"

// Constructor
HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        vector<Stock*> temp;
        Table[i] = temp;
    }
}

// De-Constructor
HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (int j = 0; j < Table[i].size(); ++j) {
            delete Table[i].at(j);
        }
        Table[i].erase(Table[i].begin(), Table[i].end());
    }
    //delete[] Table[];
}

// hash word. 137 = prime number
int HashTable::hash(std::string word) {
    int seed = 137;
    long hash = 0;
    for (int i = 0; i < word.length(); ++i) {
        hash = (hash*seed) + word[i];
    }
    return (hash % TABLE_SIZE);
}

// add Stock to Table
void HashTable::insert(Stock* stock, string name) {
    int index = hash(name);
    Table[index].push_back(stock);
}

// search for Stock in Table. Use External Chaining, if more than 1 Stock at Table[index].
Stock* HashTable::search(int index, string abbrOrName) {
    vector<Stock*> hashAtIndex = Table[index];
    if (hashAtIndex.size() == 0) { return nullptr; }
    else if (hashAtIndex.size() == 1) { return hashAtIndex.at(0); }
    else {
        for (int i = 0; i < hashAtIndex.size(); ++i) {
            if (hashAtIndex[i]->abbreviation == abbrOrName || hashAtIndex[i]->name == abbrOrName) {
                return hashAtIndex[i];
            }
        }
        return nullptr;
    }
}

// delete Stock at index, with right abbreviation
void HashTable::del(int index, string abbr) {
    delete (search(index, abbr));
    if (Table[index].size() == 1) {
        Table[index].erase(Table[index].begin());
    } else if (Table[index].size() > 1) {
        Table[index].erase(Table[index].end());
    }
}

// return Stock by index
vector<Stock*>* HashTable::getStockFromIndex(int index) {
    return &Table[index] ? &Table[index] : nullptr;
}