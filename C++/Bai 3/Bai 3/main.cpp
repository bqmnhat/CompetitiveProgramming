#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    int n,x,i;
    long long fac = 1,exp1, exp2;
    double s1 = 0.0,s2 = 0.0;
    ifstream fi;
    ofstream fo;
    fi.open("BAI3.INP");
    fo.open("BAI3.OUT");
    fi >> n >> x;
    exp1 = 1;
    exp2 = ceil(pow(x,n));
    for (int i = 1; i<=n ; i++) {
        exp1 *= x;
        fac = fac * i;
        exp2 = exp2/x;
        if (i%2 == 0) {
            s1 -= double(exp1)/double(fac);
        }
        else
            s1 += double(exp1)/double(fac);
        s2 += double(exp2)/double(fac);
    }
    fo << s1 << endl;
    fo << s2;
    fi.close();
    fo.close();
    return 0;
}
