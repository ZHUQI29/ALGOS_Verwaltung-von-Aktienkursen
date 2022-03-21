#include "SaveAndLoad.hpp"

SaveAndLoad::SaveAndLoad() {}

SaveAndLoad::~SaveAndLoad() {}

// Search for all Stocks and save each in a .csv file. Add their names to HASHNAMES.csv and save it too.
void SaveAndLoad::initializeSaving(Holder* holder) {
    vector<string> nameList;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (holder->getHashTable(false)->getStockFromIndex(i) != nullptr) {
            for (int j = 0; j < holder->getHashTable(false)->getStockFromIndex(i)->size(); ++j) {
                saveToFile(
                        holder->getHashTable(false)->getStockFromIndex(i)->at(j),
                        holder->getHashTable(false)->getStockFromIndex(i)->at(j)->name,
                        holder->getHashTable(false)->getStockFromIndex(i)->at(j)->abbreviation
                );
                nameList.push_back(holder->getHashTable(false)->getStockFromIndex(i)->at(j)->name);
            }
        }
    }
    ofstream nameFile;
    nameFile.open("HASHNAMES.csv");
    for (int i = 0; i < nameList.size(); ++i) {
        nameFile << nameList.at(i) << "\n";
    }
    nameFile.close();
}

// Save a Stock to [name].csv
void SaveAndLoad::saveToFile(Stock* stock, string name, string abbr) {
    ofstream newFile;
    newFile.open(name + ".csv");
    newFile << abbr << "\n";
    for (int i = 0; i < DAYS_TO_SAVE; ++i) {
        newFile << stock->entries[i]->date << ",";
        newFile << stock->entries[i]->open << ",";
        newFile << stock->entries[i]->high << ",";
        newFile << stock->entries[i]->low << ",";
        newFile << stock->entries[i]->close << ",";
        newFile << stock->entries[i]->adj_close << ",";
        newFile << stock->entries[i]->volume << ",\n";
    }
    newFile.close();
}

// Get all names from HASHNAMES.csv and import all Stocks by their [name].csv
void SaveAndLoad::initializeLoading(Holder* holder) {
    ifstream inFile("HASHNAMES.csv", ios::in);
    if (inFile.fail()) {
        std::cerr << "Error: Datei nicht gefunden oder kann nicht geöffnet werden" << std::endl;
    } else {
        std::cout << "loading Hashnames..\n";
        string lineStr;
        vector<string> strArray;
        while (std::getline(inFile, lineStr)) {
            strArray.push_back(lineStr);
        }
        inFile.close();

        for (int i = 0; i < strArray.size(); ++i) {
            ifstream stockFile(strArray.at(i) + ".csv", ios::in);
            if (stockFile.fail()) {
                std::cerr << "Error: Datei nicht gefunden oder kann nicht geöffnet werden" << std::endl;
            } else {
                std::cout << "loading " << strArray.at(i) <<"\n";
                lineStr = "";

                vector<string> entryArray;
                std::getline(stockFile, lineStr);
                string abbr = lineStr;
                while (std::getline(stockFile, lineStr)) {
                    entryArray.push_back(lineStr);
                }
                holder->addStock(entryArray, abbr, strArray.at(i));
                std::cout << "\ndone\n" << std::endl;
            }
        }
    }
}
