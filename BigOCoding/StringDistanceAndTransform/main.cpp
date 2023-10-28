#include <iostream>
#include <bits/stdc++.h>
#define MaxN 80
using namespace std;
int dp[MaxN+1][MaxN+1], n, m;
string s, t;

void InitDp() {
    n = s.length();
    m = t.length();
    s = ' ' + s;
    t = ' ' + t;
    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
            dp[i][j] = 0;
}

void Trace() {
    int i = n, j = m, cnt = 0;
    while ((i > 0) && (j > 0)) {
        if (s[i] == t[j]) {
            i--;
            j--;
            continue;
        }
        cnt++;
        cout << '\n' << cnt << ' ';
        if (dp[i][j] == dp[i-1][j] + 1) {
            cout << "Delete " << i;
            i--;
        }
        else if (dp[i][j] == dp[i][j-1] + 1) {
            cout << "Insert " << i+1 << ',' << t[j];
            j--;
        }
        else {
            cout << "Replace " << i << ',' << t[j];
            i--;
            j--;
        }
    }
    while (j > 0) {
        cnt++;
        cout << '\n' << cnt << ' ' << "Insert 1," << t[j--];
    }
    while (i > 0) {
        cnt++;
        cout << '\n' << cnt << ' ' << "Delete " << i--;
    }
}

void SolveTestCase() {
    for (int i=0; i<=m; i++)
        dp[0][i] = i;
    for (int i=0; i<=n; i++)
        dp[i][0] = i;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (s[i] == t[j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
        }
    }
    cout << dp[n][m];
    Trace();
}

void Solve() {
    int cnt = 0;
    while ((getline(cin, s)) && (getline(cin, t))) {
        cnt++;
        if (cnt > 1)
            cout << "\n\n";
        InitDp();
        SolveTestCase();
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
