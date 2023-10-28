#include <iostream>
#include <fstream>
using namespace std;
int FindSI(long long n) {
    long long tmp = 10, c = -1;
    int k = -1;
    while (n>1) {
        c = c + 1;
        if ((n%10 < tmp) and (n%10 != 0)) {
            tmp = n%10;
            k = c;
        }
    n = n/10;
    }
    return k;
}

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9M.INP");
    fo.open("BAI9M.OUT");
    fi >> n;
    fo << FindSI(n);
    return 0;
}
