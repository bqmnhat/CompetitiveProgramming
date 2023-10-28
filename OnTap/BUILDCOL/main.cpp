#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[100001], l[100001], r[100001], Min = 2e9, Max = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (a[i] > Max)
            Max = a[i];
        if (a[i] < Min)
            Min = a[i];
    }
}

long long CalWater(long long x) {
    long long b[100001], ans = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] < x)
            b[i] = x;
        else
            b[i] = a[i];
    }
    long long Max = 0, j;
    for (int i=1; i<=n; i++) {
        if (b[i] > Max) {
            Max = b[i];
            j = i;
        }
        l[i] = j;
    }
    Max = 0;
    for (int i=n; i>=1; i--) {
        if (b[i] > Max) {
            Max = b[i];
            j = i;
        }
        r[i] = j;
    }
    for (int i=2; i<=n-1; i++) {
        ans = ans + min(b[l[i]], b[r[i]]) - b[i];
    }
    return ans;
}

long long Solution() {
    long long Ans = -1, lo = Min, hi = Max;
    while (lo <= hi) {
        long long x = (lo+hi)/2;
        if (CalWater(x) >= m) {
            Ans = x;
            lo = x + 1;
        }
        else
            hi = x - 1;
    }
    return Ans;
}

int main()
{
    freopen("BUILDCOL.INP", "r", stdin);
    freopen("BUILDCOL.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
