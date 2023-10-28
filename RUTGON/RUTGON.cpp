#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int sum[10];

void Solve() {
    int Max = 0;
    for (int i = 0; i<s.length(); i++) {
        sum[s[i] - '0'] += s[i] - '0';
        if (sum[s[i] - '0'] > Max)
            Max = sum[s[i] - '0'];
    }
    if (Max == 0) {
        cout << 0;
    }
    for (int i=0; i<=9; i++) {
        if (sum[i] == Max)
            cout << i;
    }
}

int main()
{
    freopen("RUTGON.INP", "r", stdin);
    freopen("RUTGON.OUT", "w", stdout);
    cin >> s;
    Solve();
    return 0;
}
