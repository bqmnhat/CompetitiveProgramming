#include <iostream>
#include <fstream>
using namespace std;
ifstream fi;
ofstream fo;

long long MilkAmount(long long a, long long n, long long C) {
    long long x = (long long)C/a;
    long long y = (long long)x/n;
    return x+y;
}

int main()
{
    long long a,n,C;
    fi.open("BUYMILK.INP");
    fo.open("BUYMILK.OUT");
    fi >> a >> n >> C;
    fo << MilkAmount(a,n,C);
    return 0;
}
