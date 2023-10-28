#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m, n, a[101], b[101], dp[101][101], tra[101], trb[101], trCom[101], lt = 0;

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        cin >> b[i];
}

void TrackBack() {
    int i = m, j = n;
    while ((i > 0) && (j > 0)) {
        if (a[i] == b[j]) {
            lt++;
            trCom[lt] = a[i];
            tra[lt] = i;
            trb[lt] = j;
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i-1][j])
            i--;
        else
            j--;
    }
}

void PrintAns() {
    cout << dp[m][n] << '\n';
    for (int i=lt; i>=1; i--)
        cout << trCom[i] << ' ';
    cout << '\n';
    for (int i=lt; i>=1; i--)
        cout << tra[i] << ' ';
    cout << '\n';
    for (int i=lt; i>=1; i--)
        cout << trb[i] << ' ';
}

void Solve() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (a[i] == b[j])
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
        }
    }
    TrackBack();
    PrintAns();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("COMSEQ.INP", "r", stdin);
    freopen("COMSEQ.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    Solve();
    return 0;
}
