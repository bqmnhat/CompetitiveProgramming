#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string s;

void Solve() {
    int i = n - 1;
    while ((s[i] != '0') && (i >= 0)) {
        s[i] = '0';
        i--;
    }
    if (i >= 0) {
        s[i] = '1';
        cout << s;
    }
    else
        cout << "-1";
}

int main()
{
    freopen("BINARYGEN.INP", "r", stdin);
    freopen("BINARYGEN.OUT", "w", stdout);
    cin >> n >> s;
    Solve();
    return 0;
}
