#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[2001], trace[2001][40001], Sum = 0;
bool dp[2001][40001];
vector<int> First, Second;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        Sum += a[i];
    }
}

void Solve() {
    for (int i=0; i<=n; i++)
        dp[i][0] = true;
    for (int i=1; i<=n; i++) {
        for (int j = Sum; j>=a[i]; j--) {
            if (dp[i-1][j-a[i]]) {
                dp[i][j] = true;
                trace[i][j] = j-a[i];
            }
            else if (dp[i-1][j]) {
                dp[i][j] = true;
                trace[i][j] = j;
            }
        }
    }
    int S = 0;
    for (int i=1; 2*i<=Sum; i++) {
        if (dp[n][i])
            S = max(S, i);
    }
    cout << Sum - 2*S << '\n';
    int i = n, j = S;
    while (i >= 1) {
        if (trace[i][j] == j-a[i])
            First.push_back(i);
        else
            Second.push_back(i);
        j = trace[i][j];
        i--;
    }
    sort(First.begin(), First.end());
    sort(Second.begin(), Second.end());
    for (auto x: First)
        cout << x << ' ';
    cout << '\n';
    for (auto x: Second)
        cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("22.INP", "r", stdin);
    freopen("22.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
