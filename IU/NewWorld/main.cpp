#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int t, n, k, a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

bool Check(int len) {
    int i = 1, j = 2, Jumps = 0;
    bool Moved = false;
    while ((i <= n) && (j <= n)) {
        if (a[j] - a[i] <= len) {
            j++;
            Moved = true;
        }
        else {
            if (!Moved)
                return false;
            Moved = false;
            i = j-1;
            Jumps++;
        }
    }
    Jumps++;
    return (Jumps <= k);
}

int Solution() {
    sort(a+1, a+1+n);
    int lo = 1, hi = a[n] - a[1], mid, ans = 0;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        if (Check(mid)) {
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        ReadData();
        cout << Solution() << '\n';
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
