#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200001], b[200001], ASubB[200001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        ASubB[i] = a[i] - b[i];
    }
}

int BinSearch(int id, int lo, int hi) {
    int ans = id;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (ASubB[id] + ASubB[m] <= 0) {
            ans = m;
            lo = m + 1;
        }
        else
            hi = m - 1;
    }
    return ans;
}

long long Solution() {
    sort(ASubB + 1, ASubB + 1 + n);
    long long ans = 0;
    for (long long i=1; i<=n; i++) {
        long long tmp = BinSearch(i, i+1, n);
        if (tmp != -1)
            ans = ans + (n - tmp);
    }
    return ans;
}

int main()
{
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
