#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, h[200001], lisEnd[200001];

void ReadData() {
    for (int i =1; i<=n; i++) {
        cin >> h[i];
    }
}

int BinSearch(int val, int lo, int hi) {
    int ans = -1;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (lisEnd[m] >= val) {
            ans = m;
            hi = m-1;
        }
        else
            lo = m+1;
    }
    return ans;
}

int LIS() {
    int ans = 1;
    lisEnd[1] = h[1];
    for (int i=2; i<=n; i++) {
        if (h[i] < lisEnd[1])
            lisEnd[1] = h[i];
        else if (h[i] > lisEnd[ans]) {
            ans++;
            lisEnd[ans] = h[i];
        }
        else {
            int tmp = BinSearch(h[i], 1, ans);
            lisEnd[tmp] = h[i];
        }
    }
    return ans;
}

int main()
{
    freopen("DEFENSE.INP", "r", stdin);
    freopen("DEFENSE.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << LIS();
    return 0;
}
