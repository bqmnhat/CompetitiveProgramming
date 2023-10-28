#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9N.INP");
    fo.open("BAI9N.OUT");
    fi >> n;
    int x,c = 0,k = 0;
    while (n>0) {
        x = n%10;
        if (x == 0) {
            if (k>0) {
                c = c + 1;
            }
            k = 0;
        }
        else {
            k = k + 1;
        }
        n = n/10;
    }
    fo << c+1;
    return 0;
}
