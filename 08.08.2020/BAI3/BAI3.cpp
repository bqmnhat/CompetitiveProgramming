#include <iostream>
#include <fstream>
using namespace std;

long long EYear(long long a, long long b) {
    return b - 2*a;
}

int main()
{
    long long a,b;
    ifstream fi;
    ofstream fo;
    fi.open("BAI3.INP");
    fo.open("BAI3.OUT");
    fi >> a >> b;
    long long m = EYear(a,b);
    if (m < 0)
        fo << "cach day " << m*-1 << " nam";
    else
        fo << "sau " << m << " nam nua";
    return 0;
}
