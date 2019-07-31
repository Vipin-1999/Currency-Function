#include "currency.h"

using namespace std;
int i = 0;

void Currency :: VectorInit()      {
    std::string temp;
    ifstream in;
	in.open("cunits.txt");
    for (auto row = 0; row < 254; row++)    {
        in >> temp;
        CList.push_back(temp);
    }
    in.close();

    in.open("cunits_Abb.txt");
    for (auto row = 0; row < 254; row++)        {
        in >> temp;
        UList.push_back(temp);
    }
    in.close();
}

bool Currency::Validate(std::string unit)      {
    bool flag= std::regex_match(unit , std::regex("[A-Z]{3}"));
    bool flag1 = 0;
    if(flag == 1)
        for(int i = 0; i < 254; i++)
            if(UList.at(i) == unit)
                flag1 = 1;
    return flag1;
}

std::string Currency::GetCurrencyName(std::string unit)      {
    int pos;
    bool flag= std::regex_match(unit , std::regex("[A-Z]{3}"));
    bool flag1 = 0;
    if(flag == 1)       {
        for(auto i = UList.begin(); i != UList.end(); ++i)
            if(*i == unit)
                flag1 = 1;
            if(flag1)       {
                std::vector<std::string>::iterator it = std::find(UList.begin(), UList.end(), unit);
                pos = distance(UList.begin(), it);
                return CList.at(pos);
            }
    }
    return ("Invalid Currency");
}

std::string Currency::Random(bool x)        {
    std::string Full_number;
    srand(time(0)+(i++));
    if(x==1)
        Full_number += Generate(4);
    else
        Full_number += Generate_Invalid(5);
    return Full_number;
}

std::string Currency::Generate(int length)        {
    auto randchar = []() -> char    {
        const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length-1,0);
    srand(time(0) + i++);
    std::generate_n(str.begin(), length-1, randchar);
    return str;
}

std::string Currency::Generate_Invalid(int length)        {
    auto randchar = []() -> char    {
        const char charset[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    srand(time(0)+i++);
    std::generate_n( str.begin(), length, randchar );
    if(Validate(str))
        Generate_Invalid(length);
    return str;
}