#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, n;
ll a[MaxN+5], stGCD[4*MaxN+5], d[MaxN+5];

void ReadData() {
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void MakeD() {
    for (int i = 1; i < n; i++)
        d[i] = abs(a[i + 1] - a[i]);
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr) {
        stGCD[v] = d[tl];
        return;
    }
    int tm = ((tl + tr) >> 1);
    BuildSt(v*2, tl, tm);
    BuildSt(v*2 + 1, tm + 1, tr);
    stGCD[v] = __gcd(stGCD[v*2], stGCD[v*2 + 1]);
}

ll getRangeGCD(int v, int tl, int tr, int l, int r) {
    if ((tr < l) || (tl > r))
        return 0;
    if ((l <= tl) && (tr <= r))
        return stGCD[v];
    int tm = ((tl + tr) >> 1);
    return __gcd(getRangeGCD(v*2, tl, tm, l, r), getRangeGCD(v*2 + 1, tm + 1, tr, l, r));
}

bool checkRange(int si) {
    if (si == 1)
        return true;
    for (int i = 1; i + si - 1 <= n; i++) {
        ll rangeGCD = getRangeGCD(1, 1, n - 1, i, i + si - 2);
        if (rangeGCD >= 2)
            return true;
    }
    return false;
}

ll Solution() {
    if (n == 1)
        return 1;
    MakeD();
    BuildSt(1, 1, n - 1);
    int lo = 1, hi = n, ans = 1;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (checkRange(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
    }
    return 0;
}
