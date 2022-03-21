#ifndef AKTIEN_SAVEANDLOAD_HPP
#define AKTIEN_SAVEANDLOAD_HPP

#include <string>
#include <fstream>
#include <iostream>
#include "Holder.hpp"

class SaveAndLoad {
public:
    SaveAndLoad();
    ~SaveAndLoad();

    void saveToFile(Stock* stock, string name, string abbr);
    void initializeSaving(Holder* holder);

    void initializeLoading(Holder* holder);

private:



};


#endif //AKTIEN_SAVEANDLOAD_HPP
