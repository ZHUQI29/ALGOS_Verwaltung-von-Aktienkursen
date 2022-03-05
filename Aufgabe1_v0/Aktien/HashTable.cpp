#include "HashTable.hpp"

HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        vector<Stock*> temp;
        Table[i] = temp;
    }
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
    delete search(index, abbr);
}
