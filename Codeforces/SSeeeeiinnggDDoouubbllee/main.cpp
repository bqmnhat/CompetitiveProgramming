#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
int t;
string s;

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        cout << s;
        int l = s.length();
        for (int i=l-1; i>=0; i--)
            cout << s[i];
        cout << '\n';
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
