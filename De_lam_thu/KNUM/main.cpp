#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
struct Num {
    int val;
    int id;
}a[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].val;
        a[i].id = i;
    }
}

bool CmpNum(Num a, Num b) {
    return (a.val < b.val);
}

int BinSearch(int x) {
    int m, lo = 1, hi = n;
    while (lo <= hi) {
        m = (lo + hi)/2;
        if (a[m].id == x) {
            return m;
        }
        else if (a[m].id > x) {
            hi = m - 1;
        }
        else
            lo = m + 1;
    }
}

void Solve() {
    sort(a+1, a+1+n, CmpNum);
    int lo,hi,k;
    for (int i=1; i<=m; i++) {
        cin >> lo >> hi >> k;
        int j = BinSearch(lo), dem = 0;
        while (dem < k) {
            if ((a[j].id <= hi) && (a[j].id >= lo)) {
                dem++;
            }
            j++;
        }
        cout << a[j-1].val << endl;
    }
}

int main()
{
    freopen("KNUM.INP", "r", stdin);
    freopen("KNUM.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
