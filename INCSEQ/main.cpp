#include <iostream>
#include <bits/stdc++.h>
#define INF 1000001
using namespace std;
int n, a[1002], dp[1002], trace[1002];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Solve() {
    a[0] = -INF;
    a[n+1] = INF;
    dp[n+1] = 1;
    for (int i=n; i>=0; i--) {
        int jmax = n+1;
        for (int j=n+1; j>i; j--)
            if ((a[j] > a[i]) && (dp[j] > dp[jmax]))
                jmax = j;
        dp[i] = dp[jmax] + 1;
        trace[i] = jmax;
    }
    cout << dp[0]-2 << '\n';
    int i = trace[0];
    while (i != n+1) {
        cout << "a[" << i << ']' << " = " << a[i] << '\n';
        i = trace[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("INCSEQ.INP", "r", stdin);
    freopen("INCSEQ.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
