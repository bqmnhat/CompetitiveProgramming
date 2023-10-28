#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int k,n,m,i;
    int sum1 = 0, sum2 = 1;
    ifstream fi;
    ofstream fo;
    fi.open("BAI2.INP");
    fo.open("BAI2.OUT");
    fi >> k >> n >> m;
    long long fac = 1%m, exp = 1%m;
    for (int i = 1; i <= n; i++) {
        fac = fac*i% m;
        sum1 = (sum1 + fac)%m;
        exp = exp*k%m;
        sum2 = (sum2 + exp)%m;
    }
    fo << sum1 << endl;
    fo << sum2;
    fi.close();
    fo.close();
    return 0;
}
