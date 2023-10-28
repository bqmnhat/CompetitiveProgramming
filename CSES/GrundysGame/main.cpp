#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
int t, n, dp[MaxN+5];

void Init() {
    for (int i=1; i<=MaxN; i++)
        dp[i] = -1;
    dp[0] = dp[1] = dp[2] = 0;
}

int CalGrundy(int n) {
    if (dp[n] != -1)
        return dp[n];
    unordered_set<int> mex;
    for (int i=1; 2*i<n; i++) {
        int SubGrundyVal = (CalGrundy(i) ^ CalGrundy(n-i));
        mex.insert(SubGrundyVal);
    }
    int g = 0;
    while (mex.count(g)) g++;
    return dp[n] = g;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        if (n >= MaxN) {
            cout << "first\n";
            continue;
        }
        if (CalGrundy(n))
            cout << "first";
        else
            cout << "second";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    cin >> t;
    Solve();
    return 0;
}
