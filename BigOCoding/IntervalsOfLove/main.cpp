#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
const ll Mod = 1e9 + 7;
int t, n, m;
ll a[MaxN+1];
struct StNode {
    ll suflen, sufst, sufend, prelen, prest, preend, ans, len;
} st[4*MaxN+1]; // 1-indexed, remember l++, r++

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

StNode Combine(StNode Left, StNode Right) {
    StNode CurNode;
    if (Left.ans == -1)
        return Right;
    if (Right.ans == -1)
        return Left;
    CurNode.ans = (Left.ans + Right.ans)%Mod;
    CurNode.sufend = Right.sufend;
    CurNode.sufst = Right.sufst;
    CurNode.preend = Left.preend;
    CurNode.prest = Left.prest;
    CurNode.prelen = Left.prelen;
    CurNode.suflen = Right.suflen;
    CurNode.len = Left.len + Right.len;
    if (Left.sufend + 1 == Right.prest) {
        CurNode.ans = (CurNode.ans + (Left.suflen*Right.prelen)%Mod)%Mod;
        if (Right.suflen == Right.len) {
            CurNode.sufst = Left.sufst;
            CurNode.suflen = Left.suflen + Right.suflen;
        }
        if (Left.prelen == Left.len) {
            CurNode.preend = Right.preend;
            CurNode.prelen = Left.prelen + Right.prelen;
        }
    }
    return CurNode;
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v] = {1, a[tl], a[tl], 1, a[tl], a[tl], 1, 1};
    else {
        int tm = (tl + tr)/2;
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

void Update(int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        st[v] = {1, val, val, 1, val, val, 1, 1};
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            Update(v*2, tl, tm, id, val);
        else
            Update(v*2+1, tm+1, tr, id, val);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

StNode Query(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return {-1, -1, -1, -1, -1, -1, -1, -1};
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = (tl + tr)/2;
    return Combine(Query(v*2, tl, tm, l, r), Query(v*2+1, tm+1, tr, l, r));
}

ll Solution() {
    BuildSt(1, 1, n);
    cin >> m;
    int cmd;
    ll ans = 0;
    for (int i=1; i<=m; i++) {
        cin >> cmd;
        if (cmd == 1) {
            int l, r;
            cin >> l >> r;
            l++;
            r++;
            ans = (ans + Query(1, 1, n, l, r).ans)%Mod;
        }
        else {
            int p;
            ll k;
            cin >> p >> k;
            p++;
            Update(1, 1, n, p, k);
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << "Case #" << i << ": " << Solution() << '\n';
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
