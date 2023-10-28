#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii; // first == '(', second == ')'
int n, q, a[MaxN+1];
pii st[4*MaxN+1];
string s;

void MakeA() {
    for (int i=1; i<=n; i++) {
        if (s[i-1] == '(')
            a[i] = 1;
        else
            a[i] = -1;
    }
}

pii Combine(pii Left, pii Right) {
    pii res;
    res.first = Right.first + Left.first - min(Left.first, Right.second);
    res.second = Left.second + Right.second - min(Left.first, Right.second);
    return res;
}

void BuildSt(int v, int tl, int tr) {
    if (tl == tr) {
        if (a[tl] == 1)
            st[v].first = 1;
        else
            st[v].second = 1;
    }
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt(v*2, tl, tm);
        BuildSt(v*2+1, tm+1, tr);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

void UpdateSt(int v, int tl, int tr, int id) {
    if (tl == tr) {
        if (a[id] == 1)
            st[v] = pii(1, 0);
        else
            st[v] = pii(0, 1);
    }
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            UpdateSt(v*2, tl, tm, id);
        else
            UpdateSt(v*2+1, tm+1, tr, id);
        st[v] = Combine(st[v*2], st[v*2+1]);
    }
}

pii GetSum(int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return pii(0, 0);
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    return Combine(GetSum(v*2, tl, tm, l, r), GetSum(v*2+1, tm+1, tr, l, r));
}

void Solve() {
    BuildSt(1, 1, n);
    for (int i=1; i<=q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            swap(a[l], a[r]);
            UpdateSt(1, 1, n, l);
            UpdateSt(1, 1, n, r);
        }
        else {
            int l, r;
            cin >> l >> r;
            pii tmp = GetSum(1, 1, n, l, r);
            if ((tmp.first > 0) || (tmp.second > 0))
                cout << "No\n";
            else
                cout << "Yes\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> s;
    MakeA();
    Solve();
    return 0;
}
