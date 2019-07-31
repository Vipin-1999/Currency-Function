#include "currency.h"

using namespace std;

int main()      {
    Currency c;
    c.VectorInit();
    cout << c.GetCurrencyName("INR") << endl;
    return 0;
}