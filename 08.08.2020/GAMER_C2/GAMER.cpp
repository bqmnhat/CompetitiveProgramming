#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fi;
ofstream fo;

long long CalLevel(long long n) {
    long long delta = 1 + 8*n;
    long long m = ceil((sqrt(delta)-1)/2);
    return m;
}

int main()
{
    long long n;
    fi.open("GAMER.INP");
    fo.open("GAMER.OUT");
    fi >> n;
    fo << CalLevel(n);
    return 0;
}
