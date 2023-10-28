#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fi;
ofstream fo;

bool IsPrime(long long x) {
    for (long long i = 2; i<=(int)sqrt(x); i++) {
        if (x%i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    fi.open("BAI10.INP");
    fo.open("BAI10.OUT");
    fi >> n;
    int i = 2, k = 0;
    while (k<n) {
        if (IsPrime(i)) {
            fo << i << endl;
            k = k + 1;
        }
        i = i + 1;
    }
    return 0;
}
