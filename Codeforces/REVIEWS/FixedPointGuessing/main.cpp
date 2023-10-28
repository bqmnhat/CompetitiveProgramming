#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n;

int Question(int l, int r) {
    cout << "? " << l << ' ' << r << '\n';
    cout.flush();
    int ans = 0;
    for (int i=l; i<=r; i++) {
        int ai;
        cin >> ai;
        if ((l <= ai) && (ai <= r))
            ans++;
    }
    return ans;
}

void SolveTestCase() {
    int lo = 1, hi = n, mid;
    while (lo < hi) {
        mid = (lo + hi)/2;
        int LeftCnt = Question(lo, mid);
        if (LeftCnt%2 == 0)
            lo = mid+1;
        else
            hi = mid;
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
