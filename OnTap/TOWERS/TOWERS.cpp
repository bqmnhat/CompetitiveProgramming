#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[200001], top[200001], lt = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

int BinSearch(int val) {
    int lo = 1, hi = lt, ans = -1;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (top[m] > val) {
            ans = m;
            hi = m - 1;
        }
        else
            lo = m+1;
    }
    return ans;
}

int MinTower() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        int m = BinSearch(a[i]);
        if (m > -1)
            top[m] = a[i];
        else {
            lt++;
            top[lt] = a[i];
            ans++;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TOWERS.INP", "r", stdin);
    freopen("TOWERS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << MinTower();
    return 0;
}
