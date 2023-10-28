#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, tks[257], tkt[257];
string s,t;

void Solve() {
    int ans = 0;
    for (int i=0; i<s.length(); i++)
        tks[s[i]]++;
    for (int i=0; i<t.length(); i++)
        tkt[t[i]]++;
    for (int i=0; i<=256; i++)
        ans = ans + abs(tks[i] - tkt[i]);
    cout << ans;
}

int main()
{
    cin >> s >> t;
    Solve();
    return 0;
}
