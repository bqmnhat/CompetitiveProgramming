#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int k,n,m;
    int sum1 = 0;
    ifstream fi;
    ofstream fo;
    fi.open("BAI2.INP");
    fo.open("BAI2.OUT");
    fi >> k >> n >> m;
    long long fac = 1%m;
    for (int i = 1; i <= n; i++) {
        fac = (fac*i)% m;
        sum1 = (sum1 + fac)%m;
    }
    fo << sum1 << endl;
    fi.close();
    fo.close();
    return 0;
}
