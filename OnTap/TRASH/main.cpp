#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, t, x[1000001], cd[1000001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
}

void MakeCD() {
    for (int i=1; i<=n; i++)
        cd[i] = cd[i-1] + x[i];
}

int BinSearch(int val, int lo, int hi) {
    int ans = -1;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (val - cd[m] <= t) {
            ans = m;
            hi = m - 1;
        }
        else
            lo = m + 1;
    }
    return ans;
}

long long Solution() {
    long long ans = 0;
    for (int i=1; i<=n; i++) {
        int a = BinSearch(cd[i],0,i-1);
        if (a != -1)
            ans = ans + (i - a);
    }
    return ans;
}

int main()
{
    freopen("TRASH.INP", "r", stdin);
    freopen("TRASH.OUT", "w", stdout);
    cin >> n >> t;
    ReadData();
    MakeCD();
    cout << Solution();
    return 0;
}
