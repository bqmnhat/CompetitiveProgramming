#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, len[3001], dp[3001][10001], MaxLen, mark[3001];

void ReadData() {
    cin >> MaxLen;
    MaxLen = MaxLen*100;
    n = 0;
    while (cin >> len[n+1]) {
        n++;
        len[n] = len[n];
    }
}

void SolveTestCases() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=MaxLen; j++)
            dp[i][j] = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=MaxLen; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - len[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-len[i]] + 1);
        }
    }
    int i = n, j = MaxLen;
    while ((i > 0) && (j > 0)) {
        if (dp[i][j] == dp[i-1][j-len[i]] + 1) {
            mark[i] = true;
            j = j - len[i];
            i--;
        }
        else
            i--;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
