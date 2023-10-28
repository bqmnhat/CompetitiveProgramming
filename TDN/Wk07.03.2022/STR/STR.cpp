#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
string x, y;
ll dp[101][101];

void ReadData() {
    cin >> x >> y;
}

void Solve(string x, string y) {
    int m = x.length()+1, n = y.length()+1;
    for (int i=1; i<=n; i++)
        dp[0][i] = i;
    for (int j=1; j<=m; j++)
        dp[j][0] = j;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (x[i-1] == y[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j]))+1;
        }
    }
    cout << dp[m][n] << '\n';
    int i = m, j = n;
    while ((i > 0) || (j > 0)) {
        if (x[i-1] == y[j-1]) {
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i][j-1]+1) {
            cout << x << " -> ";
            string tmp = "";
            tmp = tmp + y[j-1];
            x.insert(i, tmp);
            cout << "Insert(" << i << ", " << y[j-1] << ")" << "->" << x;
            cout << '\n';
            j--;
        }
        else if (dp[i][j] == dp[i-1][j-1]+1){
            cout << x << " -> ";
            x[i-1] = y[j-1];
            cout << "Replace(" << i << ", " << y[j-1] << ")" << "->" << x;
            cout << '\n';
            i--;
            j--;
        }
        else {
            cout << x << " -> ";
            x.erase(i, 1);
            cout << "Delete(" << i << ")" << "->" << x;
            cout << '\n';
            i--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("STR.INP", "r", stdin);
    freopen("STR.OUT", "w", stdout);
    ReadData();
    Solve(x, y);
    return 0;
}
