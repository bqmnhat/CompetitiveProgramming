#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pdd;
ld x[MaxN+1], t[MaxN+1];
int T, n;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
    for (int i=1; i<=n; i++)
        cin >> t[i];
}

pdd Check(ld len)  {
    pdd ans;
    ld MinLeft = 1e9+1, MaxLeft = 0, MinRight = 1e9+1, MaxRight = 0;
    for (int i=1; i<=n; i++) {
        if (t[i] > len)
            return pdd(-1, -1);
        ld Left = max(ld(0.0), x[i] - (len - t[i])), Right = x[i] + (len - t[i]);
        MinLeft = min(MinLeft, Left);
        MinRight = min(MinRight, Right);
        MaxLeft = max(MaxLeft, Left);
        MaxRight = max(MaxRight, Right);
    }
    ld eps = 1e-7;
    if (MaxLeft <= MinRight - eps)
        ans = pdd(MaxLeft, MinRight);
    else
        ans = pdd(-1, -1);
    return ans;
}

void SolveTestCase() {
    ld lo = 0, hi = 1e9, eps = 1e-7;
    pdd Range;
    while (lo < hi - eps) {
        ld mid = (lo + hi)/2.0;
        pdd tmp = Check(mid);
        if (tmp.first != -1) {
            Range = tmp;
            hi = mid;
        }
        else
            lo = mid;
    }
    cout << setprecision(6) << fixed << (Range.first + Range.second)/2.0 << '\n';
}

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> n;
        ReadData();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    Solve();
    return 0;
}
