#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Holder.hpp"
#include "globals.hpp"

using namespace std;

void import(Holder* holder){
    // 读文件 Datei lesen
    std::cout << "Ziehen Sie per Drag&Drop die Datei für den import" << '\n';
    string path, abbr, name;
    std::cin >> path;
    std::cout << "\nGebens Sie den Namen der Aktie ein:";
    std::cin >> name;
    for_each(name.begin(), name.end(), convert());
    std::cout << "\nGebens Sie das Kürzel der Aktie ein:";
    std::cin >> abbr;
    for_each(abbr.begin(), abbr.end(), convert());

    ifstream inFile(path, ios::in);
    if( inFile.fail( ) ) {
        cerr << "Error: Datei nicht gefunden oder kann nicht geöffnet werden" << path <<endl<< endl;
        import(holder);  // Error;
    }
    // ifstream inFile("/Users/zhuqi/Desktop/ALGOS/Aufgabe1/MSFT.csv", ios::in);
    string lineStr;
    vector<string> strArray;
    while (getline(inFile, lineStr))
    {
        strArray.push_back(lineStr);
    }
    holder->addStock(strArray, abbr, name);
    std::cout << "\ndone: " << strArray.size() << std::endl;

}

void plotAllEntries(Stock* stock) {
    std::cout << "\nDate\t\tOpen\tHigh\tLow\tClose\tAdjCls\tVolume\n";
    for (int i = 0; i < 30; ++i) {
        std::cout << stock->entries[i]->date;
        std::cout << "\t"<< stock->entries[i]->open;
        std::cout << "\t" << stock->entries[i]->high;
        std::cout << "\t" << stock->entries[i]->low;
        std::cout << "\t" << stock->entries[i]->close;
        std::cout << "\t" << stock->entries[i]->adj_close;
        std::cout << "\t" << stock->entries[i]->volume;
        std::cout << std::endl;
    }
}

void showLastEntry(Stock* stock) {
    std::cout << stock->entries[0]->date << ": ";
    std::cout << "\tOpen: " << stock->entries[0]->open;
    std::cout << "\tHigh: " << stock->entries[0]->high;
    std::cout << "\tLow: " << stock->entries[0]->low;
    std::cout << "\tClose: " << stock->entries[0]->close;
    std::cout << "\tAdjCls: " << stock->entries[0]->adj_close;
    std::cout << "\tVolume: " << stock->entries[0]->volume;
    std::cout << std::endl;
}

Stock* search(Holder* holder) {
    std::cout << "Geben Sie Name oder Kuerzel ein: ";
    string input;
    std::cin >> input;
    for_each(input.begin(), input.end(), convert());
    Stock* result = holder->search(input);
    if (result == nullptr) {
        std::cout << "not found";
    } else {
        return result;
    }
}

char frage(){
    char a;
    std::cout << "1. ADD 2. DEL 3. IMPORT 4. SEARCH 5. PLOT 6. SAVE 7. LOAD 8. QUIT" << '\n';
    std::cin >>a;
    return a;
}

int main()
{
    Holder* holder = new Holder();
    int i=1;
    while(i){
        switch (frage()) {
            case '1':std::cerr << "noch nicht schreiben" << '\n';break;
            case '2':std::cerr << "noch nicht schreiben" << '\n';break;
            case '3':import(holder);break;
            case '4':showLastEntry(search(holder));break;
            case '5':plotAllEntries(search(holder));break;
            case '6':std::cerr << "noch nicht schreiben" << '\n';break;
            case '7':std::cerr << "noch nicht schreiben" << '\n';break;
            case '8':i=0;break;
        }
    }
    getchar();
    return 0;
}


// /home/domain/Documents/GitHub/ALGOS_Aktien/ALGOS/Aufgabe1/NTDOY.csv