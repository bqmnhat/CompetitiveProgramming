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
    int x = n+1;
    long long f, sum = 1;
    f = 1;
    for (int i = 2; i<=n; i++) {
        f = sum*n;
        sum = sum + f;
    }
    fo << f;
    return 0;
}
