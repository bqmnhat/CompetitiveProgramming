#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    long long n,d;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9H.INP");
    fo.open("BAI9H.OUT");
    fi >> n;
    d = 0;
    int m = (int)sqrt(n);
    for (int i = 1; i <= m; i++) {
        if (n%i == 0) {
            d = d + 2;
        }
    }
    if (m*m = n) {
        d = d - 1;
    }
    fo << d;
    return 0;
}
