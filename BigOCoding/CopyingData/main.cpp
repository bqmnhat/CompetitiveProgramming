#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef pair<int, int> pii;
int n, m, a[MaxN+1], b[MaxN+1], st[4*MaxN+1], lazy[4*MaxN+1];
vector<vector<int>> Type1Query;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        cin >> b[i];
}

void down(int st[], int lazy[], int v, int l, int r) {
    if (lazy[v] == 0)
        return;
    st[v] = lazy[v];
    if (l != r) {
        lazy[2*v] = lazy[v];
        lazy[2*v+1] = lazy[v];
    }
    lazy[v] = 0;
}

void UpdateSt(int st[], int lazy[], int v, int tl, int tr, int l, int r, int qid) {
    down(st, lazy, v, tl, tr);
    if ((tl > r) || (tr < l))
        return;
    if ((l <= tl) && (tr <= r)) {
        st[v] = qid;
        if (tl != tr) {
            lazy[v*2] = qid;
            lazy[v*2+1] = qid;
        }
        return;
    }
    int tm = (tl + tr)/2;
    UpdateSt(st, lazy, v*2, tl, tm, l, r, qid);
    UpdateSt(st, lazy, v*2+1, tm+1, tr, l, r, qid);
}

int QueryForQid(int st[], int lazy[], int v, int tl, int tr, int id) {
    down(st, lazy, v, tl, tr);
    if (tl == tr)
        return st[v];
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            return QueryForQid(st, lazy, v*2, tl, tm, id);
        else
            return QueryForQid(st, lazy, v*2+1, tm+1, tr, id);
    }
}

void Solve() {
    for (int i=1; i<=m; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            Type1Query.push_back({x, y, k});
            int qid = Type1Query.size();
            UpdateSt(st, lazy, 1, 1, n, y, y+k-1, qid);
        }
        else {
            int id;
            cin >> id;
            int qid = QueryForQid(st, lazy, 1, 1, n, id);
            if (qid != 0) {
                int x = Type1Query[qid-1][0], y = Type1Query[qid-1][1];
                cout << a[(id - y) + x] << '\n';
            }
            else
                cout << b[id] << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
