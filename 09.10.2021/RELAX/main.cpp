#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n;
long long a[100001], cd[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakeCD() {
    for (int i=1; i<=n; i++)
        cd[i] = cd[i-1] + a[i];
}

int BinSearch(int lo, int hi, long long val) {
    int ans = -1;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (cd[m] >= val) {
            if (cd[m] == val)
                ans = m;
            hi = m - 1;
        }
        else
            lo = m + 1;
    }
    return ans;
}

int MaxPoint(int lo, int hi) {
    long long val = (cd[hi]+cd[lo-1])/2;
    int tmp = BinSearch(lo, hi-1, val);
    if (((cd[hi]-cd[lo-1])%2 == 1) || (tmp == -1))
        return 0;
    return (1 + max(MaxPoint(lo, tmp), MaxPoint(tmp+1, hi)));
}

void Solve() {
    for (int i = 1; i<=t; i++) {
        cin >> n;
        ReadData();
        MakeCD();
        cout << MaxPoint(1, n) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("RELAX.INP", "r", stdin);
    freopen("RELAX.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
