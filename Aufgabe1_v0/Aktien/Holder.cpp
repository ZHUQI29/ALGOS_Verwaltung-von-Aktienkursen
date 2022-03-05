#include <sstream>
#include <time.h>
#include "Holder.hpp"

Holder::Holder() {
    this->hashTable = new HashTable();
    this->abbrToNameDic = new HashTable();
}

void Holder::addStock(vector<string> strArray, string abbreviation, string name) {
    StockEntry* stockEntries[30];
    for (int i = 0; i < 30; ++i) {
        vector<string> strFragments = line(strArray.at(strArray.size()-i-1));
        string date = strFragments.at(0);
        float open = std::stof(strFragments.at(1));
        float high = std::stof(strFragments.at(2));
        float low = std::stof(strFragments.at(3));
        float close = std::stof(strFragments.at(4));
        float adj_close = std::stof(strFragments.at(5));
        int volume = std::stoi(strFragments.at(6));
        stockEntries[i] = new StockEntry(date, open, high, low, close, adj_close, volume);
    }
    abbrToNameDic->insert(new Stock(abbreviation, name), abbreviation);
    hashTable->insert(new Stock(abbreviation, name,stockEntries), name);
}

vector<string> Holder::line(string str) {
    stringstream ss(str);
    string temp;
    vector<string> lineArray;
    // 按照逗号分隔durch Komma getrennt
    while (getline(ss, temp, ',')) {
        lineArray.push_back(temp);
    };
    return lineArray;
}

Stock* Holder::search(string input) {
    string name = abbrToNameDic->search(hashTable->hash(input), input)->name;
    if (name == "-") {
        return hashTable->search(hashTable->hash(input), input);
    } else {
        return hashTable->search(hashTable->hash(name), input);
    }
}

