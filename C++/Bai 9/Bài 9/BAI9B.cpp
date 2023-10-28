#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9B.INP");
    fo.open("BAI9B.OUT");
    fi >> n;
    while (n>0) {
        fo << n % 10;
        n = n/10;
    }
    return 0;
}
