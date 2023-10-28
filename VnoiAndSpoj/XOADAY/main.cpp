#include <iostream>
#include <bits/stdc++.h>
#define MaxN2Sub 100 // First 2 subs
#define MaxNLSub 1000 // Last sub
using namespace std;
typedef long long ll;
int n;
ll D[MaxNLSub+1], dp2Sub[MaxN2Sub+1][MaxN2Sub+1][MaxN2Sub+1], dpLSub[MaxNLSub+1];
string s;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> D[i];
}

void Init2Sub() {
    for (int i=0; i<=n; i++)
        for (int j=0; j<=n; j++)
            for (int k=0; k<=n; k++)
                dp2Sub[i][j][k] = -1;
}

void Dp2Sub(int i, int j, int k) {
    if ((i < 0) || (j < 0))
        return;
    if (i == j) {
        dp2Sub[i][j][k] = D[k+1];
        return;
    }
    if (i > j) {
        dp2Sub[i][j][k] = 0;
        return;
    }
    if (dp2Sub[i+1][j][0] == -1)
        Dp2Sub(i+1, j, 0);
    ll res = D[k+1] + dp2Sub[i+1][j][0];
    for (int t = i+1; t<=j; t++) {
        if (s[i] == s[t]) {
            if (dp2Sub[i+1][t-1][0] == -1)
                Dp2Sub(i+1, t-1, 0);
            if (dp2Sub[t][j][k+1] == -1)
                Dp2Sub(t, j, k+1);
            res = max(res, dp2Sub[i+1][t-1][0] + dp2Sub[t][j][k+1]);
        }
    }
    dp2Sub[i][j][k] = res;
}

void CalDpLSub() {
    for (int i=0; i<n; i++) {
        for (int j=1; j<=i+1; j++) {
            if (i - j < 0)
                dpLSub[i] = max(dpLSub[i], D[j]);
            else
                dpLSub[i] = max(dpLSub[i], dpLSub[i - j] + D[j]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    ReadData();
    if (n <= 100) {
        Init2Sub();
        Dp2Sub(0, n-1, 0);
        cout << dp2Sub[0][n-1][0];
    }
    else {
        CalDpLSub();
        cout << dpLSub[n-1];
    }
    return 0;
}
