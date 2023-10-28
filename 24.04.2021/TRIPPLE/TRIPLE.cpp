#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[5001],n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

int BinSearch(int lo, int hi, long long val) {
    int m;
    while (lo <= hi) {
        m = (lo + hi)/2;
        if (a[m] == val) {
            return m;
        }
        else if (a[m] > val) {
            hi = m - 1;
        }
        else
            lo = m + 1;
    }
    return -1;
}

bool Findj(int i, int& j, int& k) {
    for (int x=i+1; x<=n-1; x++) {
        long long m = 2*a[x] - a[i];
        int kk;
        if (a[x] == a[i])
            kk = -1;
        else
            kk = BinSearch(i+2, n, m);
        if (kk > 0) {
            j = x;
            k = kk;
            return true;
        }
    }
    return false;
}

void Solve() {
    int j,k;
    sort(a+1, a+1+n);
    for (int i=1; i<=n-2; i++) {
        if (Findj(i,j,k) == true) {
            cout << a[i] << " " << a[j] << " " << a[k];
            return;
        }
    }
    cout << "0 0 0";
}

int main()
{
    freopen("TRIPLE.INP", "r", stdin);
    freopen("TRIPLE.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
