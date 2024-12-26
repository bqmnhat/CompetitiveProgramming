#include <iostream>
#include <bits/stdc++.h>
#define MaxN 600000
using namespace std;
const int INF = 1e9 + 7;
struct Node {
    int val;
    int lazy;
};
int n, q, prefSum[MaxN+5];
string s;
Node st[4*MaxN+5]; // 1-indexed Segment Tree

void BuildSt(int v, int tl, int tr) {
    if (tl == tr)
        st[v].val = prefSum[tl];
    else {
        int tm = ((tl + tr) >> 1);
        BuildSt((v << 1), tl, tm);
        BuildSt(((v << 1) | 1), tm+1, tr);
        st[v].val = min(st[(v << 1)].val, st[((v << 1) | 1)].val);
    }
}

void down(int v) {
    int tmp = st[v].lazy;
    st[(v << 1)].lazy += tmp;
    st[(v << 1)].val += tmp;

    st[((v << 1) | 1)].lazy += tmp;
    st[((v << 1) | 1)].val += tmp;

    st[v].lazy = 0;
}

void UpdateSt(int v, int tl, int tr, int l, int r, int val) {
    if ((r < tl) || (l > tr))
        return;
    if ((l <= tl) && (tr <= r)) {
        st[v].lazy += val;
        st[v].val += val;
        return;
    }
    int tm = ((tl + tr) >> 1);
    down(v);

    UpdateSt((v << 1), tl, tm, l, r, val);
    UpdateSt(((v << 1) | 1), tm+1, tr, l, r, val);
    st[v].val = min(st[(v << 1)].val, st[((v << 1) | 1)].val);
}

int GetMin(int v, int tl, int tr, int l, int r) {
    if ((r < tl) || (l > tr))
        return INF;
    if ((l <= tl) && (tr <= r))
        return st[v].val;
    int tm = ((tl + tr) >> 1);
    down(v);
    return min(GetMin((v << 1), tl, tm, l, r), GetMin(((v << 1) | 1), tm+1, tr, l, r));
}

int MinWalkLower(int v, int tl, int tr, int l, int r, int val) {
    if (st[v].val > val)
        return -1;
    if ((l > tr) || (r < tl))
        return -1;
    if (tl == tr)
        return tl;
    int tm = ((tl + tr) >> 1);
    down(v);
    int res = -1;
    if (st[((v << 1) | 1)].val <= val)
        res = MinWalkLower(((v << 1) | 1), tm+1, tr, l, r, val);
    if (res == -1)
        res = MinWalkLower((v << 1), tl, tm, l, r, val);
    return res;
}

int MinWalkUpper(int v, int tl, int tr, int l, int r, int val) {
    if (st[v].val >= val)
        return -1;
    if ((l > tr) || (r < tl))
        return -1;
    if (tl == tr)
        return tl;
    int tm = ((tl + tr) >> 1);
    down(v);
    int res = -1;
    if (st[(v << 1)].val < val)
        res = MinWalkUpper((v << 1), tl, tm, l, r, val);
    if (res == -1)
        res = MinWalkUpper(((v << 1) | 1), tm+1, tr, l, r, val);
    return res;
}

int GetVal(int v, int tl, int tr, int id) {
    if (tl == tr)
        return st[v].val;
    int tm = ((tl + tr) >> 1);
    down(v);
    if (id <= tm)
        return GetVal((v << 1), tl, tm, id);
    return GetVal(((v << 1) | 1), tm+1, tr, id);
}

void MakeP() {
    for (int i=1; i<=n; i++) {
        int ai = 0;
        if (s[i-1] == '(')
            ai = 1;
        else
            ai = -1;
        prefSum[i] = prefSum[i-1] + ai;
    }
}

void Solve() {
    BuildSt(1, 0, n);
    int id, x;
    for (int i=1; i<=q; i++) {
        cin >> id >> x;
        int change = 0;
        if (id == 1) {
            if (s[x-1] == '(') {
                UpdateSt(1, 0, n, x, n, -2);
                s[x-1] = ')';
            }
            else {
                UpdateSt(1, 0, n, x, n, 2);
                s[x-1] = '(';
            }
        }
        else {
            int PrefSumAtXMinus1 = GetMin(1, 0, n, x-1, x-1);
            int upperBound = MinWalkUpper(1, 0, n, x, n, PrefSumAtXMinus1);
            if (upperBound == -1)
                upperBound = n;
            else
                upperBound--;
            int lowerBound = MinWalkLower(1, 0, n, x, upperBound, PrefSumAtXMinus1);
            if (lowerBound == -1)
                printf("0\n");
            else {
                int ans = lowerBound - x + 1;
                printf("%d\n", ans);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> s;
    MakeP();
    Solve();
    return 0;
}
