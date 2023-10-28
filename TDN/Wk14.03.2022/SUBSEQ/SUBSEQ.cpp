#include <iostream>
#include <bits/stdc++.h>
#define oo 1e9
using namespace std;
int n,k,dp[1001][1001], a[1001], Sum = 0, dp2[1001][1001], cnt[1001], trace[1001][1001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        Sum += a[i];
        cnt[a[i]%k]++;
    }
}

int SubOnModCriteria(int x, int y) {
    int tmp = (x-y)%k;
    if (tmp >= 0)
        return tmp;
    else
        return (tmp + k);
}

void Solve() {
    for (int i=1; i<k; i++)
        dp[0][i] = oo;
    for (int i=1; i<=n; i++)
        for (int j=0; j<k; j++)
            dp[i][j] = min(dp[i-1][j], dp[i-1][SubOnModCriteria(j, a[i])] + 1);
    cout << n - dp[n][Sum%k] << '\n';
    int CurSum = 0, j = Sum%k;
    for (int i=n; i>=1; i--) {
        if (dp[i][j] == dp[i-1][j]) {
            cout << "a[" << i << "] = " << a[i] << '\n';
            CurSum += a[i];
        }
        else
            j = SubOnModCriteria(j, a[i]);
    }
    cout << "Sum = " << CurSum;
}

void Solve2() {
    dp2[0][0] = cnt[0];
    for (int i=0; i<=k; i++)
        for (int j=0; j<k; j++)
            trace[i][j] = -1;
    trace[0][0] = cnt[0];
    for (int i=1; i<k; i++)
        for (int j=0; j<k; j++)
            for (int t = 0; t<=cnt[i]; t++)
                if ((trace[i-1][SubOnModCriteria(j, t*i)] != -1) && (dp2[i][j] < dp2[i-1][SubOnModCriteria(j, t*i)] + t)) {
                    dp2[i][j] = dp2[i-1][SubOnModCriteria(j, t*i)] + t;
                    trace[i][j] = t;
                }
    cout << dp2[k-1][0] << '\n';
    int tmp = 0;
    for (int i = k-1; i>=0; i--) {
        int j = trace[i][tmp];
        cnt[i] = j;
        tmp = SubOnModCriteria(tmp, j*i);
    }
    int CurSum = 0;
    for (int i=n; i>=1; i--)
        if (cnt[a[i]%k] > 0) {
            cout << "a[" << i << "] = " << a[i] << '\n';
            cnt[a[i]%k]--;
            CurSum += a[i];
        }
    cout << "Sum = " << CurSum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SUBSEQ.INP", "r", stdin);
    freopen("SUBSEQ.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    Solve();
    //Solve2();
    return 0;
}
