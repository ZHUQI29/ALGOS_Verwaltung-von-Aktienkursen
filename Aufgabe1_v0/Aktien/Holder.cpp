#include <sstream>
#include <time.h>
#include "Holder.hpp"

Holder::Holder() {

}

void Holder::addStock(vector<string> strArray) {
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
    stocks.push_back(new Stock("NT",stockEntries));
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