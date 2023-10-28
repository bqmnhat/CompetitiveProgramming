#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[100001], n ,s[100001], k;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

bool BinSearch(long long val, int f, int h, long long &ans) {
    while (f <= h) {
        int mid = (f+h)/2;
        if (s[mid] < k + s[val-1]) {
            f = mid + 1;
        }
        else if (s[mid] > k + s[val-1]) {
            h = mid - 1;
        }
        else {
            ans = mid;
            return true;
        }
    }
    return false;
}

void Solve() {
    for (int i=1; i<= n; i++) {
        s[i] = s[i-1] + a[i];
        if (s[i] == k) {
            cout << 1 << " " << i;
            return;
        }
    }
    long long m;
    for (int i=2; i<=n-1; i++) {
        if (BinSearch(i,i+1,n,m)) {
            cout << i << " " << m-i+1;
            return;
        }
    }
    cout << "NO";
}

int main()
{
    freopen("SUM_S.INP", "r", stdin);
    freopen("SUM_S.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    Solve();
}
