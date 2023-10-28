#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9E.INP");
    fo.open("BAI9E.OUT");
    fi >> n;
    long long x,maxev = -1;
    while (n>0) {
        x = n%10;
        if (x%2 == 0) {
            if (x > maxev) {
                maxev = x;
            }
        }
    }
    fo << maxev;
    return 0;
}
