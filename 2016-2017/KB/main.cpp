#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, tk[27];
string s;

void Solve() {
    int ans = 0, type = 0;
    for (int i = 0; i<n; i++) {
        if (tk[s[i]-'a'] == 0) {
            type++;
        }
        tk[s[i]-'a']++;
    }
    for (int i=0; i<26; i++) {
        if (tk[i] > 0)
            ans = ans + (tk[i]-1);
    }
    if (ans <= (26-type)) {
        cout << ans;
    }
    else
        cout << -1;
}

int main()
{
    freopen("KB.INP", "r", stdin);
    freopen("KB.OUT", "w", stdout);
    cin >> n >> s;
    Solve();
    return 0;
}
