#include <iostream>
#include <fstream>
using namespace std;

int FindF5(long long x){
    int tmp = 0;
    if (x%5 != 0)
        return 0;
    while ((x%5 == 0) and (x > 0)) {
        tmp = tmp + 1;
        x = x/5;
    }
    return tmp;
}

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9L.INP");
    fo.open("BAI9L.OUT");
    fi >> n;
    long long fac5 = 0,x;
    for (long long i = 2; i<=n ; i++) {
        x = i;
        fac5 = fac5 + FindF5(x);
    }
    fo << fac5;
    return 0;
}
