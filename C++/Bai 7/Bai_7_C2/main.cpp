#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI7.INP");
    fo.open("BAI7.OUT");
    fi >> n;
    long long exp = 1;
    for (int i = 3; i<=n; i++) {
        exp *= n+1;
    }
    if (n > 1)
        fo << n*exp;
    else
        fo << 1;
    return 0;
}
