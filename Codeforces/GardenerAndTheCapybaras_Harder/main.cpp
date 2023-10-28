#include <iostream>
#include <bits/stdc++.h>
#define MaxN 400000
using namespace std;
int t;
string s;

void SolveTestCase() {
    int cpos = -1, n = s.length();
    if ((s[0] == s[1]) || ((s[0] != s[1]) && (s[0] == 'b'))) {
        cout << s[0] << ' ' << s[1] << ' ' << s.substr(2, n-2) << '\n';
        return;
    }
    for (int i=2; i<n; i++) {
        if (s[i] == s[0]) {
            cpos = i;
            break;
        }
    }
    if (cpos == -1)
        cout << s[0] << ' ' << s.substr(1, n-2) << ' ' << s[n-1] << '\n';
    else
        cout << s[0] << ' ' << s.substr(1, cpos-1) << ' ' << s.substr(cpos, n-cpos) << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
