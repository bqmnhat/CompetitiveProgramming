#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pii;
int n;
pii p[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i].first >> p[i].second;
}

ld EuclideDist(pii a, pii b) {
    return ((b.first - a.first)*(b.first - a.first) + (b.second - a.second)*(b.second - a.second));
}

bool CmpPiiY(pii a, pii b) {
    return (a.second < b.second);
}

ld CalSol(int MinId, int MaxId, pii& ans1, pii& ans2) {
    ans1 = ans2 = pii(0, 0);
    if (MinId >= MaxId)
        return 8e18;
    if (MaxId - MinId <= 3) {
        ll ans = 8e18;
        for (int i=MinId; i<=MaxId; i++) {
            for (int j=i+1; j<=MaxId; j++) {
                ll tmpDist = EuclideDist(p[i], p[j]);
                if (ans > tmpDist) {
                    ans = tmpDist;
                    ans1 = p[i];
                    ans2 = p[j];
                }
            }
        }
        return ans;
    }
    int mid = ((MinId + MaxId) >> 1LL);
    pii ans1L, ans2L, ans1R, ans2R;
    ld LeftD = CalSol(MinId, mid, ans1L, ans2L), RightD = CalSol(mid+1, MaxId, ans1R, ans2R);
    ld d;
    if (LeftD < RightD) {
        d = LeftD;
        ans1 = ans1L;
        ans2 = ans2L;
    }
    else {
        d = RightD;
        ans1 = ans1R;
        ans2 = ans2R;
    }
    ld tmpDist = EuclideDist(p[mid], p[mid+1]);
    if (d > tmpDist) {
        d = tmpDist;
        ans1 = p[mid];
        ans2 = p[mid+1];
    }
    int i = mid, j = mid+1;
    vector<pii> Left, Right;
    while ((((p[i].first - p[mid].first)*(p[i].first - p[mid].first)) <= d) && (i >= MinId)) {
        Left.push_back(p[i]);
        i--;
    }
    while ((((p[j].first - p[mid+1].first)*(p[j].first - p[mid+1].first)) <= d) && (j <= MaxId)) {
        Right.push_back(p[j]);
        j++;
    }
    sort(Right.begin(), Right.end(), CmpPiiY);
    sort(Left.begin(), Left.end(), CmpPiiY);
    int t = 0;
    ld Dsqrt = sqrt(d);
    for (int i=0; i<Left.size(); i++) {
        pii x = Left[i];
        while ((t < Right.size()) && (x.second - Dsqrt > Right[t].second))
            t++;
        while ((t < Right.size()) && (Right[t].second <= x.second)) {
            ld tmpDist = EuclideDist(x, Right[t]);
            if (d < tmpDist) {
                d = tmpDist;
                ans1 = x;
                ans2 = Right[t];
            }
            t++;
        }
    }
    return d;
}

void Solve() {
    while ((cin >> n) && (n != 0)) {
        ReadData();
        sort(p+1, p+1+n);
        pii ans1, ans2;
        CalSol(1, n, ans1, ans2);
        cout << fixed << setprecision(2) << ans1.first << ' ' << ans1.second << ' ' << ans2.first << ' ' << ans2.second << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
