#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200010
using namespace std;
typedef long long ll;
int m, n, L, R, p[MaxN+2];

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> p[i];
}

bool Check(int len) {
    if (len == 0)
        return true;
    for (int i=1; i<=m+1; i++) {
        int SegLeft, SegRight;
        if (i == 1)
            SegLeft = 1;
        else
            SegLeft = p[i-1] + len;
        if (i == m+1)
            SegRight = n;
        else
            SegRight = p[i] - len;
        if (SegLeft > SegRight)
            continue;
        if (max(SegLeft, L) <= min(SegRight, R))
            return true;
    }
    return false;
}

int Solution() {
    sort(p+1, p+1+m);
    int lo = 0, hi = n, ans;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (Check(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("ELECTRIC-CAR.INP", "r", stdin);
    //freopen("ELECTRIC-CAR.OUT", "w", stdout);
    cin >> n >> m >> L >> R;
    ReadData();
    cout << Solution();
    return 0;
}
