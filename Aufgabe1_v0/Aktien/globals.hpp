#ifndef AKTIEN_GLOBALS_HPP
#define AKTIEN_GLOBALS_HPP

#define TABLE_SIZE 501
#define DAYS_TO_SAVE 30

#include <cctype>
struct convert {
    // https://stackoverflow.com/questions/735204/convert-a-string-in-c-to-upper-case
    void operator()(char& c) { c = toupper((unsigned char)c); }
};

#endif //AKTIEN_GLOBALS_HPP
