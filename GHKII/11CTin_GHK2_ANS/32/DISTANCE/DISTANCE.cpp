#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MaxN 1007
#define INF 1e9

ll n;
long double a[MaxN], b[MaxN], x, y;
void solve()
{
    long double Min = INF;
    a[n + 1] = a[1], b[n + 1] = b[1];
    for(int i = 2; i <= n + 1; ++i)
    {
        long double x1 = a[i - 1], y1 = b[i - 1], x2 = a[i], y2 = b[i];
        long double a1 = y2 - y1, b1 = x1 - x2;
        long double c = a1 * x1 + b1 * y1;
        c = -c;
        long double d = abs( (a1 * x + b1 * y + c) / sqrt(a1 * a1 + b1 * b1) );
        Min = min(Min, d);
    }
    cout << fixed << setprecision(4) << Min;
}
int main()
{
    freopen("DISTANCE.INP", "r", stdin);
    freopen("DISTANCE.OUT", "w", stdout);
    cin >> n >> x >> y;
    for(int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];
    solve();
    return 0;
}
