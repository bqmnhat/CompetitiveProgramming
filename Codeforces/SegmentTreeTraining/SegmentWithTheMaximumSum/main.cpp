#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n, m;
ll a[MaxN+1];
struct StNode {
    ll sum, pre, suf, ans;
};
StNode st[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

StNode Combine(StNode left, StNode right) {
    StNode ans;
    ans.sum = left.sum + right.sum;
    ans.pre = max(left.pre, left.sum + right.pre);
    ans.suf = max(right.suf, right.sum + left.suf);
    ans.ans = max(max(left.ans, right.ans), left.suf + right.pre);
    return ans;
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = {a[tl], max(0LL, a[tl]), max(0LL, a[tl]), max(0LL, a[tl])};
    else {
        int tm = (tl + tr)/2;
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

void Update(int v, int tl, int tr, int id, ll NewVal) {
    if (tl == tr)
        st[v] = {NewVal, max(0LL, NewVal), max(0LL, NewVal), max(0LL, NewVal)};
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            Update(v*2, tl, tm, id, NewVal);
        else
            Update(v*2+1, tm+1, tr, id, NewVal);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

void Solve() {
    ReadData();
    BuildSt(1, 1, n);
    cout << st[1].ans << '\n';
    int id;
    ll v;
    for (int i=1; i<=m; i++) {
        cin >> id >> v;
        id++;
        Update(1, 1, n, id, v);
        cout << st[1].ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    Solve();
    return 0;
}
