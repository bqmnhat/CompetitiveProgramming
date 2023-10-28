#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int n,c;

void Solve() {
    cin >> n >> c;
    cin >> s;
    for (int i = 1; i<=c; i++) {
        s = s.substr(n,s.length() - n) + s;
    }
    cout << s;
}

int main()
{
    freopen("CSTRING.INP", "r", stdin);
    freopen("CSTRING.OUT", "w", stdout);
    Solve();
    return 0;
}
