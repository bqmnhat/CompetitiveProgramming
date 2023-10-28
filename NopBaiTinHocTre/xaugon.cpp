#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s, ans;

void Solve() {
    ans = "";
    ans = ans + s[0];
    int l = s.length();
    for (int i = 1; i<l; i++) {
        if (s[i] != s[i-1])
            ans = ans + s[i];
    }
    cout << ans;
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
