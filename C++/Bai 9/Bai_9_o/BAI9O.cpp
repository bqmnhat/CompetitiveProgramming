#include <iostream>
#include <fstream>
using namespace std;

int FindMaxL(long long n) {
    int x,tmp = 0,k = 0;
    while (n>0) {
        x = n%10;
        if (x == 0) {
            if (k>tmp) {
                tmp = k;
            }
            k = 0;
        }
        else {
            k = k + 1;
        }
        n = n/10;
    }
    if (k>tmp) {
        tmp = k;
    }
    return tmp;
}

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9O.INP");
    fo.open("BAI9O.OUT");
    fi >> n;
    fo << FindMaxL(n);
    return 0;
}
