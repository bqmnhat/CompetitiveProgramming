#include <iostream>
#include <fstream>
using namespace std;
ifstream fi;
ofstream fo;

long long CalLevel(long long n) {
    long long tmp = 0, a = 0, x = n;
    while (tmp < x) {
        a = a + 1;
        tmp = tmp + a;
    }
    return a;
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
