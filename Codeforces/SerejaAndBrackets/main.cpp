#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
struct StNode {
    int Op, Cl, ans;
} st[4*MaxN+1];
int l,m;
string s;

StNode Combine(StNode l, StNode r) {
    StNode res;
    int PairUsed = min(l.Op, r.Cl);
    res.ans = l.ans + r.ans + PairUsed*2;
    res.Op = l.Op + r.Op - PairUsed;
    res.Cl = l.Cl + r.Cl - PairUsed;
    return res;
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr) {
        if (s[tl] == '(')
            st[v].Op = 1;
        else
            st[v].Cl = 1;
        st[v].ans = 0;
    }
    else {
        int tm = (tl + tr)/2;
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

StNode Query(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return {0, 0, 0};
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = (tl + tr)/2;
    return Combine(Query(v*2, tl, tm, l ,r), Query(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    BuildSt(1, 1, l);
    for (int i=1; i<=m; i++) {
        int le, ri;
        cin >> le >> ri;
        StNode tmp = Query(1, 1, l, le, ri);
        cout << tmp.ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    l = s.length();
    s = ' ' + s;
    cin >> m;
    Solve();
    return 0;
}
