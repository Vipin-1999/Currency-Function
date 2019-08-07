#ifndef CURRENCY_H
#define CURRENCY_H
#include <iostream>
#include <fstream>
#include <string> 
#include <stdexcept>
#include <regex>
typedef unsigned long size_t;
typedef std::vector<std::string> cvector;

// #include "nbind/nbind.h"

class Currency       {
    public:
    void VectorInit();
    bool Validate(std::string);
    std::string GetCurrencyName(std::string);
    std::string Random(bool); 
    std::string Generate(size_t);
    std::string Generate_Invalid(size_t);
    cvector CList, UList;
};

#endif 

// NBIND_CLASS(Currency){
//     construct<>();
//     method(VectorInit);
//     method(Validate);
//     method(Random);
//     method(Generate);
//     method(Generate_Invalid);
// }