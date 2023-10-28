#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s,x;
int f[1001][1001];

void Solve() {
    for (int i=0; i<s.length(); i++) {
        for (int j=0; j<x.length(); j++) {
            if (i == 0) {
                if (s[i] == x[j])
                    f[i][j] = f[i][j-1]+1;
            }
            else {
                if (s[i] == x[j])
                    f[i][j] = f[i][j-1] + f[i-1][j-1];
                else
                    f[i][j] = f[i][j-1];
            }
        }
    }
    cout << f[s.length()-1][x.length()-1];
}

int main()
{
    freopen("COUNTS.INP", "r", stdin);
    freopen("COUNTS.OUT", "w", stdout);
    cin >> s >> x;
    Solve();
    return 0;
}
