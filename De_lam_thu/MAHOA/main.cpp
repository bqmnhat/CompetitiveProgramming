#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s, ans;
int tk[27];

void Solve() {
    int n = 0;
    for (int i=0; i<s.length(); i++) {
        char c = s[i];
        if (c == ' ')
            continue;
        if (c < 'a')  {
            c = c + 32;
        }
        if (tk[c - 'a'] == 0) {
            ans = ans + s[i];
        }
        tk[c - 'a']++;
    }
    for (int i=0; i<=26; i++) {
        if (tk[i] > 1) {
            n = n + tk[i];
        }
    }
    cout << n << " " << ans;
}

int main()
{
    freopen("MAHOA.INP", "r", stdin);
    freopen("MAHOA.OUT", "w", stdout);
    getline(cin, s);
    Solve();
    return 0;
}
