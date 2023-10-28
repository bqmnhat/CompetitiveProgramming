#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k, la = 0;
string s;
char a[256];

void Solve() {
    for (int i=0; i<n; i++) {
        while ((la > 0) && (a[la] < s[i]) && (k > 0)) {
            la--;
            k--;
        }
        la++;
        a[la] =  s[i];
    }
    for (int i=k; i>0; i--) {
        la--;
    }
    for (int i=1; i<=la; i++) {
        cout << a[i];
    }
}

int main()
{
    freopen("CHUSO.INP", "r", stdin);
    freopen("CHUSO.OUT", "w", stdout);
    cin >> s >> k;
    n = s.length();
    Solve();
    return 0;
}
