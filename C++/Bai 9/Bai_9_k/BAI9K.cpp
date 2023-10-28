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
        while (n%i==0) {
            fo << i << " ";
            n = n/i;
        }
        i++;
    }
    if (n>1) {
        fo << n;
    }
    return 0;
}
