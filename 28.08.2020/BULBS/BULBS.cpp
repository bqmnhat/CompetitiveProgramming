#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fi;
ofstream fo;

bool IsON(long long n) {
    long long m = (int)sqrt(n);
    return (m*m == n);
}

int main()
{
    long long n;
    fi.open("BULBS.INP");
    fo.open("BULBS.OUT");
    fi >> n;
    if (IsON(n))
        fo << "ON";
    else
        fo << "OFF";
    return 0;
}
