#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct meet {
    int st,fi,id; // type = 0 is start; type = 1 is finish
} a[1000001];
int c[1000001], tv[1000001], n, b[1000001], lb = 0;;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].st >> a[i].fi;
        a[i].id = i;
    }
}

bool CmpFin(meet a, meet b) {
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
        tv[i] = id;
    }
    int Max = 1;
    for (int i=2; i<=1000000; i++) {
        if (c[i] > c[Max]) {
            Max = i;
        }
    }
    cout << c[Max] << endl;
    while (Max > 0) {
        lb++;
        b[lb] = a[Max].id;
        Max = tv[Max];
    }
    for (int i=lb; i>=1; i--) {
        cout << b[i] << endl;
    }
}

int main()
{
    freopen("MEETING.INP", "r", stdin);
    freopen("MEETING.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}

