#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[100001], h[10000001];
int i2 = 1, i3 = 1, i5 = 1, n, l;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void MoveNext(long long val) {
    if (val%2==0)
        i2++;
    if (val%3==0)
        i3++;
    if (val%5==0)
        i5++;
}

void Gen() {
    long long a2, a3, a5, i = 1;
    h[1] = 1;
    while (h[i-1] < 1000000000000000000) {
        ++i;
        a2 = h[i2]*2;
        a3 = h[i3]*3;
        a5 = h[i5]*5;
        h[i] = min(a2, min(a3,a5));
        MoveNext(h[i]);
    }
    l=i;
}

int BinSearch(long long val) {
    int lo = 1, hi = l;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (h[mid] > val) {
            hi = mid-1;
        }
        else if (h[mid] < val) {
            lo = mid + 1;
        }
        else
            return mid;
    }
    return -1;
}

void Solve() {
    for (int i=1; i<=n; i++) {
        int x = BinSearch(a[i]);
        if (x > 0) {
            cout << x << endl;
        }
        else
            cout << "Not in sequence" << endl;
    }
}

int main()
{
    freopen("HAMMING.INP", "r", stdin);
    freopen("HAMMING.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Gen();
    Solve();
    return 0;
}
