#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    int d;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9K.INP");
    fo.open("BAI9K.OUT");
    fi >> n;
    long long i = 2,m = (int)sqrt(n);
    while ((n>1) and (i<=m)) {
        d = 0;
        while (n%i==0) {
            d = d + 1;
            n = n/i;
        }
        for (int j = 1; j<=d; j++) {
            fo << i << " ";
        }
        i++;
    }
    if (n>1) {
        fo << n;
    }
    return 0;
}
