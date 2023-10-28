#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[100001], k;
int n;
struct CongDon {
    long long val;
    int id;
} cd[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] = a[i] - k;
        cd[i].val = cd[i-1].val + a[i];
        cd[i].id = i;
    }
}

bool CmpCD(CongDon a, CongDon b) {
    if (a.val == b.val) {
        return (a.id < b.id);
    }
    else
        return (a.val < b.val);
}

void Solve() {
    sort(cd,cd+1+n, CmpCD);
    int i=0,j = 1,st = n + 1, l = 0;
    while (i<=n) {
        while ((cd[j].val == cd[i].val) && (j<=n)) j++;
        if (cd[j-1].val - cd[i].val == 0) {
            if (cd[j-1].id - cd[i].id > l) {
                st = cd[i].id+1;
                l = cd[j-1].id - cd[i].id;
            }
            if ((cd[j-1].id - cd[i].id == l) && (cd[i].id+1 < st))
                st = cd[i].id+1;
        }
        i=j;
    }
    if (l == 0)
        cout << "0";
    else
        cout << l << " " << st;
}

int main()
{
    freopen("CUBICS.INP", "r", stdin);
    freopen("CUBICS.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    Solve();
    return 0;
}
