#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s, mau = "TRUNG TUYEN 2021";

void Solve() {
    int l = 0, ans = 0;
    for (int i=0; i<s.length(); i++) {
        if (l > s.length()-1) {
            ans++;
            l = 0;
        }
        if (s[i] > 'Z') {
            s[i] = s[i] - 32;
        }
        if (s[i] == mau[l]) {
            l++;
        }
        if (s[i] != mau[l]) {
            l = 0;
        }
    }
    cout << ans;
}

int main()
{
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    cin >> s;
    Solve();
    return 0;
}

