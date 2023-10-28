#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int k,n,m;
    int sum2 = 1;
    ifstream fi;
    ofstream fo;
    fi.open("BAI2.INP");
    fo.open("BAI2.OUT");
    fi >> k >> n >> m;
    long long exp = 1%m;
    for (int i = 1; i <= n; i++) {
        exp = (exp*k)%m;
        sum2 = (sum2 + exp)%m;
    }
    fo << sum2 << endl;
    fi.close();
    fo.close();
    return 0;
}
