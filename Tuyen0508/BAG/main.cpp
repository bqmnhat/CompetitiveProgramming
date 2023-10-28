#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxV 200000
using namespace std;
typedef long long ll;
int n;
ll v0, MaxP, dp[MaxN+5][MaxV+5];
struct Product{
    ll v, c, p;
} a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].v >> a[i].c >> a[i].p;
        MaxP = max(MaxP, a[i].p);
    }
}

bool CmpProduct(Product a, Product b) {
    if (a.p == b.p) {
        if (a.c == b.c)
            return (a.v < b.v);
        return (a.c > b.c);
    }
    return (a.p > b.p);
}

ll SolutionFirst2Sub() {
    ll ans = 0;
    for (int i=1; i < (1 << n); i++) {
        int mask = i, cnt = 0;
        ll TotalV = 0;
        ll MinP = 1e9 + 7, tmp = 0;
        while (mask > 0) {
            cnt++;
            if (mask&1) {
                MinP = min(MinP, a[cnt].p);
                tmp += a[cnt].c;
                TotalV += a[cnt].v;
            }
            mask >>= 1LL;
        }
        if (TotalV - v0 <= MinP)
            ans = max(ans, tmp);
    }
    return ans;
}

ll SolutionLast2Sub() {
    ll VMax = v0 + MaxP;
    ll ans = 0;
    sort(a+1, a+1+n, CmpProduct);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=VMax; j++) {
            dp[i][j] = dp[i-1][j];
            if ((j - a[i].v >= 0) && (j - v0 <= a[i].p))
                dp[i][j] = max(dp[i][j], dp[i-1][j - a[i].v] + a[i].c);
        }
    }
    for (int i=1; i<=MaxV; i++)
        ans = max(ans, dp[n][i]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> v0;
    ReadData();
    if (n <= 20)
        cout << SolutionFirst2Sub();
    else
        cout << SolutionLast2Sub();
    return 0;
}
