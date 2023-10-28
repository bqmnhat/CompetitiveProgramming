#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct seg {
    long long st,fi;
} a[1001];
long long c[1001], Time[1001];
int n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].st >> a[i].fi;
    }
}

bool CmpFin(seg a, seg b) {
    if (a.st < b.st)
        return true;
    else if (a.st > b.st)
        return false;
    return (a.fi < b.fi);
}

void Solve() {
    sort(a+1, a+1+n, CmpFin);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<i; j++) {
            if ((c[j] == c[i]) && (a[j].fi < a[i].st))
                Time[i] += Time[j];
            if ((c[j] > c[i]) && (a[j].fi < a[i].st)) {
                c[i] = c[j];
                Time[i] = Time[j];
            }
        }
        c[i]++;
    }
    int Max = 0, MaxTime = 0;
    for (int i=1; i<=n; i++) {
        if (c[i] > Max) {
            Max = c[i];
        }
    }
    for (int i=1; i<=n; i++) {
        if (c[i] == Max)
            MaxTime += Time[i];
    }
    cout << Max << " " << MaxTime;
}

int main()
{
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
