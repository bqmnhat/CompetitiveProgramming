#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
double x[10001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> x[i];
    }
}

int BinSearch(double val) {
    int lo = 1, hi = n, m;
    while (lo <= hi) {
        m = (lo + hi)/2;
        if (x[m] > val) {
            hi = m - 1;
        }
        else if (x[m] < val) {
            lo = m + 1;
        }
        else
            return m;
    }
    return -1;
}

int CompareDouble(double &a, double &b) {
    if (abs(a-b) < 1e-10)
        a = b;
    return (a < b);
}

int Solution() {
    int ans = 0;
    sort(x+1,x+1+n, CompareDouble);
    for (int i=1; i<=n; i++) {
        for (int j=i+2; j<=n; j++) {
            if (BinSearch((x[i] + x[j])/2) > 0) {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    freopen("CHIADEU.INP", "r", stdin);
    freopen("CHIADEU.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
