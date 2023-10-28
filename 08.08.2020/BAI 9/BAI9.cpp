#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
ifstream fi;
ofstream fo;

double CalHeight(int a, double b, long long n) {
    double x = a;
    double m = b/100;
    for (long long i = 1; i<=n; i++) {
        x = x + x*m;
    }
    return x;
}

int main()
{
    int a;
    double b;
    long long n;
    fi.open("BAI9.INP");
    fo.open("BAI9.OUT");
    fi >> a >> b >> n;
    double m = CalHeight(a,b,n);
    fo << setprecision(3) << fixed << m;
    return 0;
}
