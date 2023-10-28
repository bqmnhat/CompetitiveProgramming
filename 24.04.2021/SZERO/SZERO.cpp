#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct CDArr {
    long long Val;
    int id;
} cd[100001];
long long a[100001];
int n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void MakeCD() {
    for (int i=1; i<=n; i++) {
        cd[i].Val = cd[i-1].Val + a[i];
        cd[i].id = i;
    }
}

bool CmpCD(CDArr a, CDArr b) {
    if (a.Val == b.Val) {
        return (a.id < b.id);
    }
    return (a.Val < b.Val);
}

void Solve() {
    sort(cd, cd+1+n, CmpCD);
    int MaxL = 0, lo, hi, i=0, j;
    while (i<=n) {
        j = i+1;
        while ((cd[j].Val == cd[i].Val) && (j<=n)) {
            j++;
        }
        if (cd[j-1].Val - cd[i].Val == 0) {
            if (cd[j-1].id - cd[i].id > MaxL) {
                lo = cd[i].id+1;
                hi = cd[j-1].id;
                MaxL = cd[j-1].id - cd[i].id;
            }
        }
        i = j;
    }
    cout << lo << " " << hi;
}

int main()
{
    freopen("SZERO.INP", "r", stdin);
    freopen("SZERO.OUT", "w", stdout);
    cin >> n;
    ReadData();
    MakeCD();
    Solve();
    return 0;
}
