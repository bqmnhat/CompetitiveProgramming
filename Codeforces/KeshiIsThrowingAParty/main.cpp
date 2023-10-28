#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[200001], b[200001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i] >> b[i];
}

bool CanInvite(int x) {
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if ((x-1-a[i] <= cnt) && (cnt <= b[i]))
            cnt++;
    }
    if (cnt >= x)
        return true;
    else
        return false;
}

int Solution() {
    int lo = 1, hi = n, ans;
    while (lo <= hi) {
        int m = ((lo + hi)>>1);
        if (CanInvite(m)) {
            ans = m;
            lo = m + 1;
        }
        else
            hi = m - 1;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
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
