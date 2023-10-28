#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
string s;

void SolveTestCase() {
    int cntN = 0, l = s.length();
    for (int i=0; i<l; i++) {
        if (s[i] == 'N')
            cntN++;
    }
    if (cntN == 1)
        cout << "NO" << '\n';
    else
        cout << "YES" << '\n';
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
