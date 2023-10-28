#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long sum = 0, a[200001], t, cd[200001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

void MakeCD() {
    for (int i=1; i<=2*n; i++)
        cd[i] = cd[i-1]+ a[i];
}

int BinSearch(int x, int lo, int hi) {
    int ans = 0;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (cd[m] - cd[x-1] <= t) {
            ans = m;
            lo = m+1;
        }
        else
            hi = m-1;
    }
    return ans;
}

long long Solution() {
    long long Max = 0;
    for (int i=1; i<=n; i++) {
        int x = BinSearch(i, i, n);
        if (x - i + 1 > Max)
            Max = x - i + 1;
    }
    return Max;
}

int main()
{
    cin >> n >> t;
    ReadData();
    MakeCD();
    cout << Solution();
    return 0;
}
