#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int UCLN(int a, int b) {
    int c;
    while (b != 0) {
        c = b;
        b = a%b;
        a = c;
    }
    return a;
}

int SoDao(int x) {
    int ans = 0;
    while (x > 0) {
        ans = ans*10 + x%10;
        x = x/10;
    }
    return ans;
}

void Solve() {
    for (int i = 10; i<=99; i++) {
        if (UCLN(i,SoDao(i)) == 1)
            cout << i << endl;
    }
}

int main()
{
    freopen("THANTHIEN.OUT", "w", stdout);
    Solve();
    return 0;
}
