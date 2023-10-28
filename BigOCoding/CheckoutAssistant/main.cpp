#include <iostream>
#include <bits/stdc++.h>
#define MaxLL 10000000000000ll
using namespace std;
typedef long long ll;
int n;
ll c[2001], t[2001], dp[2001][2001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> t[i] >> c[i];
}

ll Backtrack(int i, ll Time) {
    if (Time >= n)
        return 0;
    if (i > n)
        return MaxLL;
    if (dp[i][Time] != 0)
        return dp[i][Time];
    dp[i][Time] = min(Backtrack(i+1, Time), (Backtrack(i+1, Time + t[i] + 1) + c[i]));
    return dp[i][Time];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Backtrack(1, 0);
    return 0;
}
