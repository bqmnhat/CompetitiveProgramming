#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI6.INP");
    fo.open("BAI6.OUT");
    fi >> n;
    long long f[n];
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i<=n; i++){
        f[i] = f[i-1] + f[i-2];
    }
    fo << f[n];
    return 0;
}
