#include <iostream>
#include <fstream>
using namespace std;
long long FindY(long long n) {
    long long tmp = 0;
    while (n>=5) {
        tmp = tmp + n/5;
        n = n/5;
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
    fo << FindY(n);
    return 0;
}
