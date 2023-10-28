#include <iostream>
#include <bits/stdc++.h>
#define MaxN 30
using namespace std;
int t, n, ls, dp[MaxN+1][MaxN+1];
string s, w[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> w[i];
}

int Grundy(int l, int r) {
    if (l > r)
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    unordered_set<int> mex;
    for (int j=1; j<=n; j++) {
        int ws = w[j].length();
        for (int i=l; i<=r-ws+1; i++) {
            int tmpi = i, tmpj = 0;
            while ((tmpi < ls) && (tmpj < ws) && (s[tmpi] == w[j][tmpj])) {
                tmpi++;
                tmpj++;
            }
            if (tmpj >= ws)
                mex.insert(Grundy(l, i-1)^Grundy(i + ws, r));
        }
    }
    int g = 0;
    while (mex.count(g))
        g++;
    return dp[l][r] = g;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s >> n;
        ls = s.length();
        ReadData();
        memset(dp, -1, sizeof(dp));
        if (Grundy(0, ls-1) == 0)
            cout << "Tracy";
        else
            cout << "Teddy";
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
