#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000000
using namespace std;
typedef long long ll;
int n;
ll p, q, m, k, a[MaxN+5], SparseTableMax[MaxN+5][25], SparseTableMin[MaxN+5][25];
ll log_2[MaxN+5];
map<ll, ll> cntVal;

void ReadData() {
    for (ll i=1; i<=n; i++) {
        a[i] = (p*1LL*i + q)%m;
        cntVal[a[i]]++;
    }
}

void MakeLog2() {
    for (int i=2; i<=n; i++)
        log_2[i] = log_2[i/2] + 1;
}

void MakeSparse() {
    for (int i=1; i<=n; i++)
        SparseTableMax[i][0] = SparseTableMin[i][0] = a[i];
    for (int j=1; (1<<j) <= n; j++) {
        int step = 1 << (j-1);
        for (int i=1; i+2*step <= n+1; i++) {
            SparseTableMax[i][j] = max(SparseTableMax[i][j-1], SparseTableMax[i+step][j-1]);
            SparseTableMin[i][j] = min(SparseTableMin[i][j-1], SparseTableMin[i+step][j-1]);
        }
    }
}

ll MinQuery(int l, int r) {
    int k = log_2[r-l+1];
    return (min(SparseTableMin[l][k], SparseTableMin[r - (1 << k) + 1][k]));
}

ll MaxQuery(int l, int r) {
    int k = log_2[r-l+1];
    return (max(SparseTableMax[l][k], SparseTableMax[r - (1 << k) + 1][k]));
}

ll CountSubMin(ll k, int id, ll val) {
    ll target = val - k, ans = -1;
    ll lo = 2, hi = id;
    while (lo <= hi) {
        ll mid = (lo + hi)/2;
        if (MaxQuery(id - mid + 1, id) - MinQuery(id - mid + 1, id) <= k) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

ll Solution() {
    MakeLog2();
    MakeSparse();
    ll ans = n;
    for (int i=1; i<=n; i++) {
        ll tmp = CountSubMin(k, i, a[i]);
        tmp--;
        if (tmp <= 0)
            continue;
        ans = ans + tmp;
    }
    for (auto p: cntVal) {
        ll fi = p.first, se = p.second;
        ans = ans - (se*(se-1LL))/2;
    }
    return ans;
}

ll Solution2() {
    ll res = 0;
    ll MinVal = 1e10, MaxVal = -1e10;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            MinVal = min(MinVal, a[j]);
            MaxVal = max(MaxVal, a[j]);
            if (MaxVal - MinVal <= k) res++;
        }
        MinVal = 1e10;
        MaxVal = -1e10;
    }
    return res;
}

int main()
{
    freopen("SDIFF.INP", "r", stdin);
    freopen("SDIFF.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> p >> q >> m;
    cin >> k;
    ReadData();
    if (n <= 10000)
        cout << Solution2();
    else
        cout << Solution();
    return 0;
}
