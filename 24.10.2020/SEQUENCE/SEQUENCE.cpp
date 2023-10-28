#include <iostream>
#include <cstdio>
using namespace std;
int a[82];

int SoDao(int a) {
    int ans = 0;
    while (a > 0) {
        ans = ans*10 + a%10;
        a = a/10;
    }
    return ans;
}

void Sinh(int a[]) {
    a[1] = 10;
    for (int i = 2; i<=81; i++) {
        a[i] = SoDao(a[i-1]) + 2;
    }
}

void Solve() {
    long long k;
    while (cin >> k) {
        if (k == 1)
            cout << 1 << endl;
        else if (k % 81 == 0)
            cout << a[81];
        else
            cout << a[k%81] << endl;
    }
}

int main()
{
    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);
    Sinh(a);
    Solve();
    return 0;
}
