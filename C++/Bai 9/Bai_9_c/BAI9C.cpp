#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9C.INP");
    fo.open("BAI9C.OUT");
    fi >> n;
    int sum = 0;
    while (n>9) {
        sum = sum + (int)abs(n%10 - ((n%100)/10));
        n = n/10;
    }
    fo << sum;
    return 0;
}
