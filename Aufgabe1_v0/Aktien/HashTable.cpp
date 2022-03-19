#include "HashTable.hpp"

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        vector<Stock*> temp;
        Table[i] = temp;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (int j = 0; j < Table[i].size(); ++j) {
            delete Table[i].at(j);
        }
        Table[i].erase(Table[i].begin(), Table[i].end());
    }
    //delete[] Table[];
}

int HashTable::hash(std::string word) {
    int seed = 137;
    long hash = 0;
    for (int i = 0; i < word.length(); ++i) {
        hash = (hash*seed) + word[i];
    }
    return (hash % TABLE_SIZE);
}

void HashTable::insert(Stock* stock, string name) {
    int index = hash(name);
    Table[index].push_back(stock);
}

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

void HashTable::del(int index, string abbr) {
    delete (search(index, abbr));
    if (Table[index].size() == 1) {
        Table[index].erase(Table[index].begin());
    } else if (Table[index].size() > 1) {
        Table[index].erase(Table[index].end());
    }
}

vector<Stock*>* HashTable::getStockFromIndex(int index) {
    return &Table[index] ? &Table[index] : nullptr;
}