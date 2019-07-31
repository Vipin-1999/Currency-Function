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
    std::string Generate(int);
    std::string Generate_Invalid(int);
    cvector CList, UList;
};

#endif 

/* NBIND_CLASS(Currency){
    construct<>();
    multimethod(Validate, args(std::string), "Validate");
    multimethod(Validate, args(std::string, std::string), "ValidateWithAreaCode");
    multimethod(Random, args(bool), "Random");
    multimethod(Random, args(bool, std::string), "RandomWithAreaCode");
    method(Ccode);
    method(Generate);
    method(Generate_Invalid);
} */