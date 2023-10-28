#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, n, k, st[4*MaxN + 5];
vector<int> a[MaxN+5];

void ReadData() {
    for (int i=0; i<n; i++) {
        int k;
        cin >> k;
        a[i].clear();
        int Mx = 0;
        for (int j=0; j<k; j++) {
            int aj;
            cin >> aj;
            Mx = max(Mx, aj);
            a[i].push_back(aj);
        }
        a[i].push_back(Mx);
    }
}

void UpdateSt(int v, int tl, int tr, int id, int val, bool reset) {
    if (tl == tr) {
        if (reset)
            st[v] = val;
        else
            st[v] = max(st[v], val);
    }
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val, reset);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val, reset);
        st[v] = max(st[v*2], st[v*2+1]);
    }
}

int MaxQuerry(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return (max(MaxQuerry(v*2, tl, tm, l, r), MaxQuerry(v*2+1, tm+1, tr, l, r)));
}

bool CmpVec(const vector<int>& a, const vector<int>& b) {
    return (a.back() < b.back());
}

void SolveTestCases() {
    sort(a, a+n, CmpVec);
    for (int i=0; i<n; i++) {
        auto &vec = a[i];
        int la = vec.size(), mx = 0, MxEle = 0;
        vector<int> stk;
        vector<int> cost(la, 0);
        for (int i=la-2; i>=0; i--) {
            while ((!stk.empty()) && (stk.back() <= vec[i]))
                stk.pop_back();
            stk.push_back(vec[i]);
            cost[i] = stk.size();
        }
        for (int i=0; i<la-1; i++) {
            if (vec[i] <= MxEle)
                continue;
            mx = max(mx, MaxQuerry(1, 1, MaxN, 1, vec[i] - 1) + cost[i]);
            MxEle = max(MxEle, vec[i]);
        }
        UpdateSt(1, 1, MaxN, vec.back(), mx, false);
    }
    cout << st[1] << '\n';
    for (int i=0; i<n; i++) {
        auto &vec = a[i];
        UpdateSt(1, 1, MaxN, vec.back(), 0, true);
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        SolveTestCases();
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
