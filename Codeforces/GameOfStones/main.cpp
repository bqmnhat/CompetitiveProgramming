#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
#define MaxS 60
using namespace std;
int n, s[MaxN+1];
map<vector<int>, int> dp[MaxS+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> s[i];
}

int CalDp(int s, const vector<int>& mask) {
    if (s == 0)
        return 0;
    if (dp[s].find(mask) != dp[s].end())
        return dp[s][mask];
    unordered_set<int> mex;
    vector<int> Nxt = mask;
    for (int i=1; i<=s; i++) {
        Nxt.pop_back();
        if (mask[i] == 0) {
            if (2*i <= s)
                Nxt[i] = 1;
            mex.insert(CalDp(s - i, Nxt));
            if (2*i <= s)
                Nxt[i] = 0;
        }
    }
    int g = 0;
    while (mex.count(g))
        g++;
    return dp[s][mask] = g;
}

void Solve() {
    int res = 0;
    vector<int> InitMask;
    for (int i=1; i<=n; i++) {
        InitMask.assign(s[i]+1,0);
        res ^= CalDp(s[i], InitMask);
    }
    if (res)
        cout << "NO";
    else
        cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
