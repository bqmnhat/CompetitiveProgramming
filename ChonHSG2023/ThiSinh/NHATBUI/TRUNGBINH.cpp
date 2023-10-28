#include <iostream>
#include <bits/stdc++.h>;
#define MaxNSub1 1000
#define MaxN 1000005
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
int n;
ll a[MaxN+5], pref[MaxN+5], st[4*MaxN+5], p;
vector<int> ForSort;
unordered_map<ll, ll> ma;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    cin >> p;
}

//first sub

ll SolutionSub1() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        ll curSum = 0;
        for (int j=i; j>=1; j--) {
            curSum += a[j];
            if (curSum >= p*(i - j + 1LL))
                ans++;
        }
    }
    return ans;
}

//LastSubSolution

void Compress() {
    ForSort.push_back(0);
    for (int i=1; i<=n; i++) {
        a[i] -= p;
        pref[i] = pref[i-1] + a[i];
        ForSort.push_back(pref[i]);
    }
    sort(ForSort.begin(), ForSort.end());
    int cnt = 0;
    for (int i=0; i<ForSort.size(); i++) {
        if (ma[ForSort[i]] == 0) {
            cnt++;
            ma[ForSort[i]] = cnt;
        }
    }
    for (int i=0; i<=n; i++)
        pref[i] = ma[pref[i]];
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = 0;
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = st[v*2] + st[v*2+1];
    }
}

void UpdateSt(int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        st[v] += val;
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = st[v*2] + st[v*2+1];
    }
}

ll GetMin(int v, int tl, int tr, int l, int r) {
    if ((tr < l) || (tl > r))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    ll ans = GetMin(v*2, tl, tm, l, r) + GetMin(v*2+1, tm+1, tr, l, r);
    return ans;
}

ll Solution() {
    BuildSt(1, 0, MaxN);
    UpdateSt(1, 0, MaxN, pref[0], 1);
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        ll MinID = GetMin(1, 0, MaxN, 0, pref[i]);
        UpdateSt(1, 0, MaxN, pref[i], 1);
        ans += MinID;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TRUNGBINH.INP", "r", stdin);
    freopen("TRUNGBINH.OUT", "w", stdout);
    cin >> n;
    ReadData();
    if (n <= 1000)
        cout << SolutionSub1();
    else {
        Compress();
        cout << Solution();
    }
    return 0;
}
