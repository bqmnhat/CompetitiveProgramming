#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 100000
#define MaxH 1000000
int k;
long long m[MaxN+1], sum = 0, wood[MaxH+1], h[MaxN+1], tk[MaxH+1], n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> h[i];
        sum += h[i];
        tk[h[i]]++;
    }
    for (int i=1; i<=k; i++)
        cin >> m[i];
}

void MakeWood() {
    for (long long saw = 0; saw <= MaxH; saw++) {
        n = n - tk[saw];
        sum = sum - tk[saw]*saw;
        wood[saw] = sum - n*saw;
    }
}

int BinSearch(long long val) {
    int lo = 0, hi = 1000000, ans = -1;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (wood[m] >= val) {
            ans = m;
            lo = m + 1;
        }
        else
            hi = m - 1;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=k; i++)
        cout << BinSearch(m[i]) << " ";
}

int main()
{
    freopen("SAW.INP", "r", stdin);
    freopen("SAW.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    MakeWood();
    Solve();
    return 0;
}
