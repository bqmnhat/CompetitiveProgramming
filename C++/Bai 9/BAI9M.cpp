#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9M.INP");
    fo.open("BAI9M.OUT");
    fi >> n;
    long long tmp = 0, c = 0, k;
    while (n%10 == 0) {
        n = n / 10;
        c = c + 1;
    }
    tmp = n%10;
    n = n/10;
    k = c;
    while (n>1) {
        c = c + 1;
        if ((n%10 < tmp) and (n%10 != 0)) {
            tmp = n%10;
            k = c;
        }
        n = n/10;
    }
    fo << k;
    return 0;
}
