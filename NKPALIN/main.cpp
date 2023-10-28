#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s, ans = "";
int f[2002][2002];

void Solve() {
    s = " " + s;
    int n = s.length();
    for (int i=1; i<=n; i++) {
        for (int j=n; j>=1; j--) {
            if (s[i] == s[j]) {
                f[i][j] = f[i-1][j+1] + 1;
            }
            else {
                f[i][j] = max(f[i-1][j], f[i][j+1]);
            }
        }
    }
    int i=n, j=1;
    while ((i >= 1) && (j <= n)) {
        if (s[i] == s[j]) {
            ans = ans + s[i];
            i--;
            j++;
        }
        else if (f[i][j] == f[i-1][j]) {
            i--;
        }
        else
            j++;
    }
    cout << ans;
}

int main()
{
    cin >> s;
    Solve();
    return 0;
}
