#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 200000
int n;
long long t;
struct Comp {
    long long val;
    int id;
}a[MaxN+1];

void ReadData() {
    for (int i=1; i<= n; i++) {
        cin >> a[i].val;
        a[i].id = i;
    }
}

bool CmpComp(Comp a, Comp b) {
    return (a.val < b.val);
}

int BinSearch(int lo, int hi, long long val) {
    int ans = 0;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (a[m].val <= val) {
            ans = m;
            lo = m + 1;
        }
        else
            hi = m - 1;
    }
    return ans;
}

void Solve() {
    sort(a+1, a+1+n, CmpComp);
    long long ans = 0;
    int ansi, ansj;
    for (int i=1; i<=n; i++) {
        long long tmp = t/a[i].val;
        int pos1 = BinSearch(1, i-1, tmp);
        int pos2 = BinSearch(i+1, n, tmp);
        if (a[pos1].val*a[i].val > ans) {
            ans = a[pos1].val*a[i].val;
            ansi = pos1;
            ansj = i;
        }
        if (a[pos2].val*a[i].val > ans) {
            ans = a[pos2].val*a[i].val;
            ansi = i;
            ansj = pos2;
        }
    }
    if (ans != 0)
        cout << ans << '\n' << a[ansi].id << " " << a[ansj].id;
    else
        cout << '0';
}

int main()
{
    freopen("MAXPRODUCT.INP", "r", stdin);
    freopen("MAXPRODUCT.OUT", "w", stdout);
    cin >> n >> t;
    ReadData();
    Solve();
    return 0;
}
