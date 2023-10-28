#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
string s;

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        if (((s[0] == 'Y') || (s[0] == 'y')) && ((s[1] == 'E') || (s[1] == 'e')) && ((s[2] == 's') || (s[2] == 'S')))
            cout << "YES\n";
        else
            cout << "NO\n";
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
