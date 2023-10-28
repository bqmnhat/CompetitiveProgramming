#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    int n,x,s = 0;
    long long fac = 1,exp2;
    ifstream fi;
    ofstream fo;
    fi.open("BAI3.INP");
    fo.open("BAI3.OUT");
    fi >> n >> x;
    exp2 = 1;
    for (int i = 1; i<=n ; i++) {
        exp2 = exp2 * i;
        s = x*s + 1/exp2;
    }
    fo << s2 << endl;
    fi.close();
    fo.close();
    return 0;
}
