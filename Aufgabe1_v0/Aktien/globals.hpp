#ifndef AKTIEN_GLOBALS_HPP
#define AKTIEN_GLOBALS_HPP

#define TABLE_SIZE 501

struct convert {
    void operator()(char& c) { c = toupper((unsigned char)c); }
};

#endif //AKTIEN_GLOBALS_HPP
