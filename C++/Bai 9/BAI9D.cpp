#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9D.INP");
    fo.open("BAI9D.OUT");
    fi >> n;
    int tmp = 0;
    while (n>9) {
        if ((int)abs(n%10 - ((n%100)/10)) > tmp) {
            tmp = (int)abs(n%10 - ((n%100)/10));
        }
        n = n/10;
    }
    fo << tmp;
    return 0;
}
