#include <iostream>
#include <cstdio>
using namespace std;

int UCLN(int a, int b) {
    int tmp = 0;
    while (b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int BCNN(int a, int b) {
    return (a*b)/UCLN(a,b);
}

int main()
{
    int a,b,c;
    freopen("BCNN_3.inp", "r", stdin);
    freopen("BCNN_3.out", "w", stdout);
    cin >> a >> b >> c;
    if ((a >= 0) && (b >= 0) && (c >= 0))
        cout << BCNN(BCNN(a,b),c);
    return 0;
}
