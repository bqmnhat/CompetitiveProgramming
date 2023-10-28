#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T;
long long r,t;

long long BinSearch() {
    long long a = sqrt(t), b = t/r;
    long long lo = 1, hi = (long long)min(a,b), ans;
    while (lo <= hi) {
        long long m = (lo + hi)/2;
        if ((2*(m*m) + m*(2*r - 1LL)) <= t) {
            ans = m;
            lo = m+1;
        }
        else
            hi = m-1;
    }
    return ans;
}

void Solve() {
    for (int i = 1; i<=T; i++) {
        cin >> r >> t;
        cout << "Case #" << i << ": " << BinSearch() << '\n';
    }
}

int main()
{
    cin >> T;
    Solve();
    return 0;
}
