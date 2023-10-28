#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct seg {
    long long st,fi;
} a[50001];
int n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].st >> a[i].fi;
    }
}

bool CmpFin(seg a, seg b) {
    return (a.fi < b.fi);
}

int Solution() {
    sort(a+1, a+1+n, CmpFin);
    int c = 1;
    int r = a[c].fi;
    for (int i=2; i<=n; i++) {
        if (r <= a[i].st) {
            c++;
            r = a[i].fi;
        }
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}

