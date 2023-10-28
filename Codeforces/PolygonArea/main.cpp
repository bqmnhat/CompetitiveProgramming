#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long double ld;
typedef long long ll;
const ld Pi = acos(-1);
const ld EPS = 1e-9;
int n, x[MaxN + 5], y[MaxN + 5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i] >> y[i];
}

ld Solution() {
    ld ans = 0;
    for (int i=1; i<n; i++)
        ans += (x[i]*y[i+1] - y[i]*x[i+1]);
    ans += (x[n]*y[1] - y[n]*x[1]);
    ans = abs(ans/2.0);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("area.in", "r", stdin);
    freopen("area.out", "w", stdout);
    cin >> n;
    ReadData();
    cout << fixed << setprecision(8) << Solution();
    return 0;
}
