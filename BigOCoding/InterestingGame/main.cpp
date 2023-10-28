#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, dp[MaxN+5], MinK[MaxN+5];

bool IsCp(int x) {
    int m = sqrt(x);
    return (m*m == x);
}

int Grundy(int x) {
    if (x <= 2)
        return dp[x] = 0;
    if (dp[x] != -1)
        return dp[x];
    unordered_set<int> mex;
    int m = sqrt(2*x), tmp = 0, prek = 1;
    for (int k=2; k<=m; k++) {
        if ((2*x - k*k + k) % (2*k) == 0) {
            int Alpha = (2*x - k*k + k) / (2*k);
            tmp = 0;
            for (int j=Alpha; j<=Alpha+k-1; j++)
                tmp ^= Grundy(j);
            if ((tmp == 0) && (MinK[x] == -1))
                MinK[x] = k;
            mex.insert(tmp);
        }
    }
    int g = 0;
    while (mex.count(g))
        g++;
    return dp[x] = g;
}

int Solution() {
    memset(dp, -1, sizeof(dp));
    memset(MinK, -1, sizeof(MinK));
    if (Grundy(n) == 0)
        return -1;
    return MinK[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << Solution();
    return 0;
}
