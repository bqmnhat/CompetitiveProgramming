#include <iostream>
#include <bits/stdc++.h>
#define MaxN 101
using namespace std;
int t, n, dp[MaxN+1][3][3], CurPlayer = 0; // 0 is Alice, 1 is Bob
char mv[3] = {'#', 'X', 'O'};
string s;

int Grundy(int l, int Left, int Right) {
    if (l == 0)
        return 0;
    if (dp[l][Left][Right] != -1)
        return dp[l][Left][Right];
    unordered_set<int> mex;
    for (int i=1; i<=l; i++) {
        for (int j=1; j<=2; j++) {
            if ((i == 1) && (mv[Left] == mv[j]))
                continue;
            if ((i == l) && (mv[Right] == mv[j]))
                continue;
            mex.insert(Grundy(i-1, Left, j) ^ Grundy(l - i, j, Right));
        }
    }
    int g = 0;
    while (mex.count(g))
        g++;
    return dp[l][Left][Right] = g;
}

void Solve() {
    memset(dp, -1, sizeof(dp));
    for (int i=1; i<=t; i++) {
        cin >> s;
        n = s.length();
        CurPlayer = 0;
        int st, ed, len = 0, res = 0;
        st = ed = 0;
        for (int j = 0; j<n; j++) {
            if (s[j] == '.')
                len++;
            else {
                if (s[j] == 'X')
                    ed = 1;
                else
                    ed = 2;
                res ^= Grundy(len, st, ed);
                len = 0;
                st = ed;
                CurPlayer = 1 - CurPlayer;
            }
        }
        res ^= Grundy(len, st, 0);
        if (res == 0) {
            if (CurPlayer == 0)
                cout << "Impossible.";
            else
                cout << "Possible.";
        }
        else {
            if (CurPlayer == 0)
                cout << "Possible.";
            else
                cout << "Impossible.";
        }
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
