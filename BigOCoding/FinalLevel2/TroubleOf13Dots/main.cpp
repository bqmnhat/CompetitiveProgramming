#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int m, n, p[101], f[101], dp[20001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i] >> f[i];
}

void Init() {
    for (int i=1; i<=m; i++)
        dp[i] = 0;
}

int Solution() {
    for (int i=1; i<=n; i++)
        for (int j=m; j>=p[i]; j--)
            dp[j] = max(dp[j], dp[j - p[i]] + f[i]);
    int MoneyUsed = m;
    while ((MoneyUsed > 0) && (dp[MoneyUsed] == dp[MoneyUsed - 1]))
        MoneyUsed--;
    if ((MoneyUsed <= 2000) && (m > 2000))
        return dp[m-200];
    else
        return dp[m];
}

void Solve() {
    while (cin >> m >> n) {
        ReadData();
        if (m > 1800)
            m += 200;
        Init();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
