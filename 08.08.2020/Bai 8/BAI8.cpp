#include <iostream>
#include <fstream>
using namespace std;

long long CalDay(long long a, long long n) {
    int k = 0;
    while (a<n) {
        a = a*2;
        k = k + 1;
    }
    return k;
}

int main()
{
    long long a,n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI8.INP");
    fo.open("BAI8.OUT");
    fi >> a >> n;
    fo << CalDay(a,n);
    return 0;
}
