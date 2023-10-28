#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long long n, cs = 0;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9A.INP");
    fo.open("BAI9A.OUT");
    fi >> n;
    while (n>0) {
        n = n/10;
        cs = cs + 1;
    }
    return 0;
}
