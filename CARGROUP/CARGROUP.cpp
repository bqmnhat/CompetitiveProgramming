#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, P, L, w[1001], v[1001], EndGroup[1001];
double f[1002], t[1001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> w[i] >> v[i];
        t[i] = double(L)/double(v[i]);
    }
}

void Solve() {
    f[0] = 0;
    for (int i=1; i<=n; i++) {
        double SumWeight = 0, MaxTime = 0;
        f[i] = 1e18;
        for (int j=i; j>=1; j--) {
            SumWeight += w[j];
            if (SumWeight > P)
                break;
            MaxTime = max(MaxTime, t[j]);
            double tmp = f[j-1] + MaxTime;
            if (f[i] > tmp) {
                f[i] = tmp;
                EndGroup[i] = j-1;
            }
        }
    }
    cout << fixed << setprecision(2) << f[n] << '\n';
    /*int i=n;
    int ans[1001], la = 0;
    while (i >= 1) {
        la++;
        ans[la] = i;
        i = EndGroup[i];
    }
    for (int i=la; i>=1; i--)
        cout << ans[i] << ' ';
    */
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CARGROUP.INP", "r", stdin);
    freopen("CARGROUP.OUT", "w", stdout);
    cin >> n >> P >> L;
    ReadData();
    Solve();
    return 0;
}
