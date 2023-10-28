#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
int n, log_2[MaxN+1];
ll x, y, a[MaxN+1], pref[MaxN+1], sptMin[MaxN+1][20];
pii stMax[4*MaxN+1];
int Pos[MaxN+1], lp = 0;

void MakeLog2() {
    log_2[0] = log_2[1] = 0;
    for (int i=2; i<=n; i++)
        log_2[i] = log_2[i/2] + 1;
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if ((a[i] <= y) && (a[i] >= x)) {
            lp++;
            Pos[lp] = i;
        }
        sptMin[i][0] = a[i];
        pref[i] = pref[i-1] + a[i];
    }
}

void SptInit() {
    int step;
    for (int j = 1; (1 << j) <= n; j++) {
        step = (1 << (j-1));
        for (int i=1; i + 2*step <= n+1; i++)
            sptMin[i][j] = min(sptMin[i][j-1], sptMin[i + step][j-1]);
    }
}

ll MinQuery(int l, int r) {
    int k = log_2[r - l + 1];
    return (min(sptMin[l][k], sptMin[r - (1 << k) + 1][k]));
}

pii CombineMax(pii Left, pii Right) {
    if (Left.first > Right.first)
        return Left;
    return Right;
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        stMax[v] = pii(pref[tl], tl);
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        stMax[v] = CombineMax(stMax[v*2], stMax[v*2+1]);
    }
}

pii MaxQuery(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return (pii(-1e18, 0));
    if ((l <= tl) && (tr <= r))
        return stMax[v];
    int tm = ((tl + tr) >> 1);
    return CombineMax(MaxQuery(v*2, tl, tm, l, r), MaxQuery(v*2+1, tm+1, tr, l, r));
}

int BinSearchGTE(int id, ll val) {
    int lo = id, hi = n, ans = -1;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        ll tmpMin = MinQuery(id, mid);
        if (tmpMin >= val) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

int BinSearchLTE(int id) {
    int lo = 1, hi = lp, ans = -1;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (Pos[mid] <= id) {
            ans = Pos[mid];
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

void Solve() {
    ll ans = -1e18;
    int L, R;
    for (int i=1; i<=n; i++) {
        if (a[i] < x)
            continue;
        int UpperBound = BinSearchGTE(i, x);
        int tmp = BinSearchLTE(UpperBound);
        if ((tmp == -1) || (tmp < i))
            continue;
        pii tmpQuery = MaxQuery(1, 1, n, i, UpperBound);
        if (tmpQuery.first - pref[i-1] > ans) {
            ans = tmpQuery.first - pref[i-1];
            L = i;
            R = tmpQuery.second;
        }
    }
    cout << ans << '\n' << L << ' ' << R << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x >> y;
    MakeLog2();
    ReadData();
    SptInit();
    BuildSt(1, 1, n);
    Solve();
    return 0;
}
