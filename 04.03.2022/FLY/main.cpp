#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int n, h[100001], c[100001], MaxHeight = 0;
ll down = 0, up = 0, sum[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> h[i];
        MaxHeight = max(MaxHeight, h[i]);
    }
    for (int i=1; i<=n; i++) {
        cin >> c[i];
        sum[h[i]] += c[i];
        down += c[i];
    }
}

void Solve() {
    ll MinCost = 0, HwMinCost = 0, cost = 0; //HwMinCost is the height with min cost
    for (int i = 1; i<=n; i++)
        cost += 1LL*h[i]*c[i];
    MinCost = cost;
    for (int i=1; i<=MaxHeight; i++) {
        cost = cost - down + up;
        if (sum[i] != 0) {
            down -= sum[i];
            up += sum[i];
        }
        if (cost < MinCost) {
            MinCost = cost;
            HwMinCost = i;
        }
    }
    cout << HwMinCost << ' ' << MinCost;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FLY.INP", "r", stdin);
    freopen("FLY.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
