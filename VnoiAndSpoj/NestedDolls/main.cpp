#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20000
#define MaxVal 10005
using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
int t, m, dpLNonIS[MaxN+5], st[4*MaxVal + 5];
// The number of Increasing subsequence == the longest non increasing subsequence
// Proof:
// Call a1 < a2 < a3 < ... < ak and b1 < b2 < b3 < ... < bk and c1 < c2 < c3 < ... < ck are Increasing subsequences
// if ak <= bk <= ck and the indexes of ak, bk, ck in the array that we used to find the ISs are ia, ib, ic, respectively
// ia > ib > ic must hold (ia != ib != ic because they are indexes which are distinct values on the same array)
// => ic < ib < ia and ck >= bk >= ak => Longest non increasing subsequence
pii Dolls[MaxN+5];

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> Dolls[i].first >> Dolls[i].second;
    Dolls[m+1] = pii(MaxVal, 0);
}

bool CmpDolls(pii a, pii b) {
    if (a.first == b.first)
        return a.second > b.second;
    return (a.first < b.first);
}

void AddSt(int v, int tl, int tr, int id, int val) {
    if (tl == tr) {
        if (dpLNonIS[val] > dpLNonIS[st[v]])
            st[v] = val;
    }
    else {
        int tm = ((tl + tr) >> 1);
        if (id <= tm)
            AddSt(v*2, tl, tm, id, val);
        else
            AddSt(v*2+1, tm+1, tr, id, val);
        if (dpLNonIS[st[v*2]] > dpLNonIS[st[v*2+1]])
            st[v] = st[v*2];
        else
            st[v] = st[v*2+1];
    }
}

int FindMax(int v, int tl, int tr, int l, int r) {
    if ((r < tl) || (tr < l))
        return INF;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = ((tl + tr) >> 1);
    int id1 = FindMax(v*2, tl, tm, l, r), id2 = FindMax(v*2+1, tm+1, tr, l, r);
    if (id1 == INF)
        return id2;
    if (id2 == INF)
        return id1;
    if (dpLNonIS[id1] > dpLNonIS[id2])
        return id1;
    else
        return id2;
}

int Solution() {
    memset(dpLNonIS, 0, sizeof(dpLNonIS));
    memset(st, 0, sizeof(st));
    sort(Dolls+1, Dolls+1+m, CmpDolls);
    for (int i=1; i<=m+1; i++) {
        int id = FindMax(1, 0, MaxVal, Dolls[i].second, MaxVal);
        dpLNonIS[i] = max(1, dpLNonIS[id] + 1);
        AddSt(1, 0, MaxVal, Dolls[i].second, i);
    }
    return dpLNonIS[m+1]-1;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> m;
        ReadData();
        cout << Solution() << '\n';
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
