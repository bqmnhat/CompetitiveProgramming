#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
int t, n;

int Query(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    int ai, cnt = 0;
    for (int i=l; i<=r; i++) {
        cin >> ai;
        if ((l <= ai) && (ai <= r))
            cnt++;
    }
    return cnt;
}

void SolveTestCase() {
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi)/2;
        int Left = Query(lo, mid);
        if (Left%2)
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << "? " << lo << ' ' << hi << '\n';
    cout.flush();
    int ai;
    cin >> ai;
    cout << "! " << ai << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        SolveTestCase();
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
