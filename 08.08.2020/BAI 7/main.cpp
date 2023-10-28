#include <iostream>
#include <fstream>
using namespace std;

long long a,b,c;
ifstream fi;
ofstream fo;

void BuyCake(long long a, long long b, long long c) {
    long long x = 0,y, m = (int)c/a;
    while (x<=m) {
        if ((c - a*x) % b == 0) {
            y = (c - a*x) / b;
            fo << x << " " << y << endl;
        }
        x += 1;
    }
}

int main()
{
    fi.open("BAI7.INP");
    fo.open("BAI7.OUT");
    fi >> a >> b >> c;
    BuyCake(a,b,c);
    return 0;
}
