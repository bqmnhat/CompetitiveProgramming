#include <iostream>
#include <bits/stdc++.h>
#define MaxN2Sub 1000
#define MaxK2Sub 10
using namespace std;
typedef long long ll;
int dp2Sub[MaxN2Sub+1][MaxK2Sub+1], n, k;
ll a[MaxN2Sub+1], d;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void InitDp2Sub() {
    for (int i=1; i<=n; i++)
        dp2Sub[i][0] = 1;
}

int Solution() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=k; j++) {
            dp2Sub[i][j] = dp2Sub[i][j-1];
            for (int t=1; t<i; t++) {
                ll c = abs(a[i] - a[t] - d);
                if (j - c >= 0)
                    dp2Sub[i][j] = max(dp2Sub[i][j], dp2Sub[t][j-c] + 1);
            }
        }
    }
    int ans = 0;
    for (int i=0; i<=k; i++)
        ans = max(ans, dp2Sub[n][i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d >> k;
    ReadData();
    if ((n <= 1000) && (k <= 10)) {
        InitDp2Sub();
        cout << Solution();
    }
    return 0;
}
