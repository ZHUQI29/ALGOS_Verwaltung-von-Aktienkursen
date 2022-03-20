#include <sstream>
#include <time.h>
#include <iostream>
#include "Holder.hpp"

// Constructor
Holder::Holder() {
    this->hashTable = new HashTable();
    this->abbrToNameDic = new HashTable();
}

// De-Constructor
Holder::~Holder() {
    delete hashTable;
    delete abbrToNameDic;
}

// Create a new Stock and add it to both hash tables.
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

// get an array from a string of data, seperated by commas
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

// begin search for Stock, based on input
Stock* Holder::search(string input) {
    int hashedInput = hashTable->hash(input);
    Stock* stock = abbrToNameDic->search(hashedInput, input);
    if (stock == nullptr) {
        return hashTable->search(hashedInput, input);
    } else {
        string name = stock->name;
        return hashTable->search(hashTable->hash(name), input);
    }
}

// delete Stock from table
void Holder::del(string input) {
    Stock* stock = search(input);
    if (stock == nullptr) {
        std::cout << "\nNichts zum Löschen." << std::endl;
    } else {
        string abbr = stock->abbreviation;
        abbrToNameDic->del(hashTable->hash(stock->abbreviation), stock->abbreviation);
        hashTable->del(hashTable->hash(stock->name), stock->abbreviation);
        std::cout << "\n Gelöscht.";
    }
}

// return one of both hashtables.
HashTable* Holder::getHashTable(bool abbrTable) {
    if (abbrTable) {
        return abbrToNameDic;
    } else {
        return hashTable;
    }
}


