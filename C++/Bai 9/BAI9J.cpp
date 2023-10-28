#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9J.INP");
    fo.open("BAI9J.OUT");
    fi >> n;
    int tmp = 0,c = 0,x;
    while (n>0) {
        x = n%10;
        if (x>tmp) {
            tmp = x;
            c = 0;
        }
        if (x = tmp) {
            c = c + 1;
        }
        n = n/10;
    }
    fo << tmp << " " <<c;
    return 0;
}
