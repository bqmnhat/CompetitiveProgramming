#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct seg {
    long long st,fi;
} a[50001];
long long c[50001];
int n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].st >> a[i].fi;
    }
}

bool CmpFin(seg a, seg b) {
    return (a.fi < b.fi);
}

int BinSearch(int lo, int hi, int val) {
    int m;
    int ans = 0;
    while (lo <= hi) {
        m = (lo + hi)/2;
        if (a[m].fi <= val) {
            if (c[m] > c[ans]) {
                ans = m;
            }
            lo = m + 1;
        }
        else
            hi = m - 1;
    }
    return ans;
}

void Solve() {
    sort(a+1, a+1+n, CmpFin);
    c[1] = 1;
    for (int i=2; i<=n; i++) {
        int id = BinSearch(1, i-1, a[i].st);
        c[i] = c[id] + 1;
    }
    int Max = 0;
    for (int i=1; i<=n; i++) {
        if (c[i] > Max) {
            Max = c[i];
        }
    }
    cout << Max;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DOANTHANG.INP", "r", stdin);
    freopen("DOANTHANG.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}

