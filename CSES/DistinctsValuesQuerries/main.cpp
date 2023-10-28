#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
struct Querry {
    int p1, p2, id;
} Q[MaxN+1];
int n, q;
ll st[4*MaxN+1], x[MaxN+1], ans[MaxN+1];
map<ll, int> PrevPos;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i];
    for (int i=1; i<=q; i++) {
        cin >> Q[i].p1 >> Q[i].p2;
        Q[i].id = i;
    }
}

void UpdateSt(int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        st[v] = val;
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id, val);
        else
            UpdateSt(v*2+1, tm+1, tr, id, val);
        st[v] = st[v*2] + st[v*2+1];
    }
}

ll SumQuerry(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return (SumQuerry(v*2, tl, tm, l, r) + SumQuerry(v*2+1, tm+1, tr, l, r));
}

bool CmpQuerries(Querry a, Querry b) {
    return (a.p2 < b.p2);
}

void Solve() {
    sort(Q+1, Q+1+q, CmpQuerries);
    int j = 1;
    for (int i=1; i<=n; i++) {
        if (PrevPos.find(x[i]) != PrevPos.end())
            UpdateSt(1, 1, n, PrevPos[x[i]], 0);
        UpdateSt(1, 1, n, i, 1);
        PrevPos[x[i]] = i;
        while ((j <= n) && (Q[j].p2 < i))
            j++;
        while ((j <= n) && (Q[j].p2 == i)) {
            ans[Q[j].id] = SumQuerry(1, 1, n, Q[j].p1, Q[j].p2);
            j++;
        }
    }
    for (int i=1; i<=q; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    Solve();
    return 0;
}
