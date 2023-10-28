#include <iostream>
#include <fstream>
using namespace std;
long long FindMax(long long n) {
    long long x,y = 1,val = 0,tmp = 0;
    while (n>0) {
        if (x == 0) {
            if (val > tmp) {
                tmp = val;
            }
            val = 0;
            y = 1;
            continue;
        }
        x = n%10;
        val = (y*x) + val;
        y = y * 10;
        n = n/10;
    }
    if (val > tmp) {
        tmp = val;
    }
    return tmp;
}

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9P.INP");
    fo.open("BAI9P.OUT");
    fi >> n;
    fo << FindMax(n);
    return 0;
}
