#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    int n,x;
    long long fac = 1,exp1;
    double s1 = 0.0;
    ifstream fi;
    ofstream fo;
    fi.open("BAI3.INP");
    fo.open("BAI3.OUT");
    fi >> n >> x;
    exp1 = 1;
    for (int i = 1; i<=n ; i++) {
        exp1 *= x;
        fac = fac * i;
        if (i%2 == 0) {
            s1 -= double(exp1)/double(fac);
        }
        else
            s1 += double(exp1)/double(fac);
    }
    fo << s1 << endl;
    fi.close();
    fo.close();
    return 0;
}
