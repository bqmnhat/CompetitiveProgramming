#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

void Solve() {
    int l = s.length();
    if (l == 0)
        return;
    cout << s[0];
    for (int i = 1; i<l; i++) {
        if (s[i] != s[i-1])
            cout << s[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xaugon.inp", "r", stdin);
    freopen("xaugon.out", "w", stdout);
    getline(cin, s);
    Solve();
    return 0;
}
