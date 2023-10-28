#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, a[MaxN+1], st[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = 1;
    else {
        int tm = (tl + tr)/2;
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = st[v*2] + st[v*2+1];
    }
}

void UpdateById(int v, int tl, int tr, int id) {
    if (tl == tr)
        st[v] = 0;
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateById(v*2, tl, tm, id);
        else
            UpdateById(v*2+1, tm+1, tr, id);
        st[v] = st[v*2] + st[v*2+1];
    }
}

int FindKthOne(int v, int tl, int tr, int k) {
    if (st[v] < k)
        return -1;
    if (tl == tr)
        return tl;
    int tm = (tl + tr)/2;
    if (st[v*2] >= k)
        return FindKthOne(v*2, tl, tm, k);
    else
        return FindKthOne(v*2+1, tm+1, tr, k - st[v*2]);
}

void Solve() {
    vector<int> res;
    for (int i=n; i>=1; i--) {
        int ans = n - FindKthOne(1, 1, n, a[i] + 1) + 1;
        res.push_back(ans);
        UpdateById(1, 1, n, n - ans + 1);
    }
    reverse(res.begin(), res.end());
    for (auto x: res)
        cout << x << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    BuildSt(1, 1, n);
    Solve();
    return 0;
}
