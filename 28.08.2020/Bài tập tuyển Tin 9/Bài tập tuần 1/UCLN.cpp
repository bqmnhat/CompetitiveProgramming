#include <iostream>
#include <cstdio>
#include <cmath>
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

int main()
{
    int a,b;
    freopen("UCLN.inp", "r", stdin);
    freopen("UCLN.out", "w", stdout);
    cin >> a >> b;
    if ((a >= 0) && (b >= 0))
        cout << UCLN(a,b);
    return 0;
}
