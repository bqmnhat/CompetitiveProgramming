#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
long long k, x;

long long CalMess(long long a) {
    return ((1LL*a*(a+1LL))/2);
}

long long BinSearch(long long k, long long x) {
    long long lo = 1, hi = 2*k-1LL, ans = 2*k-1LL;
    while (lo <= hi) {
        long long TotalEmoj = 0, m = (lo + hi)/2;
        if (m < k)
            TotalEmoj = CalMess(m);
        else
            TotalEmoj = CalMess(k) + CalMess(k-1) - CalMess(2*k - 1LL - m);
        if (TotalEmoj >= x) {
            ans = m;
            hi = m - 1LL;
        }
        else
            lo = m + 1LL;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> k >> x;
        cout << BinSearch(k,x) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
