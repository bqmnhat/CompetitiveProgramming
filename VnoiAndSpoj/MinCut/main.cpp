#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 7;
int m, n, k, x, y, u, v;
ll a[MaxN+5][MaxN+5], sum[MaxN+5][MaxN+5];

void ReadData() {
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
}

void MakeSum() {
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
}

ll SumOfRec(int x1, int y1, int x2, int y2) {
    return (sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]);
}

ll SolutionX() {
    int lo = x, hi = u-1, ID = x;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (SumOfRec(x, y, mid, v) <= SumOfRec(mid+1, y, u, v)) {
            ID = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    ll ans = abs(SumOfRec(ID+1, y, u, v) - SumOfRec(x, y, ID, v));
    if (ID + 1 < u)
        ans = min(ans, abs(SumOfRec(ID+2, y, u, v) - SumOfRec(x, y, ID+1, v)));
    return ans;
}

ll SolutionY() {
    int lo = y, hi = v-1, ID = y;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (SumOfRec(x, y, u, mid) <= SumOfRec(x, mid+1, u, v)) {
            ID = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    ll ans = abs(SumOfRec(x, y, u, ID) - SumOfRec(x, ID+1, u, v));
    if (ID + 1 < v)
        ans = min(ans, abs(SumOfRec(x, y, u, ID+1) - SumOfRec(x, ID+2, u, v)));
    return ans;
}

ll Solution() {
    ll ans = INF;
    if (x < u)
        ans = min(ans, SolutionX());
    if (y < v)
        ans = min(ans, SolutionY());
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n >> k;
    ReadData();
    MakeSum();
    for (int i=1; i<=k; i++) {
        cin >> x >> y >> u >> v;
        cout << Solution() << '\n';
    }
    return 0;
}
