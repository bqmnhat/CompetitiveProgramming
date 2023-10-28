#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define MaxSum 400000
using namespace std;
typedef pair<int, int> pii;
string s;
pii pref[MaxN+2];
int stMax[4*MaxSum+1], n;
bool IsVowel[257];
const int Base = 200000;

void Init() {
    IsVowel['u'] = IsVowel['e'] = IsVowel['o'] = IsVowel['a'] = IsVowel['i'] = IsVowel['U'] = IsVowel['E'] = IsVowel['O'] = IsVowel['A'] = IsVowel['I'] = true;
}

void MakePref() {
    for (int i=0; i<n; i++) {
        if (IsVowel[s[i]])
            pref[i].first = -1;
        else
            pref[i].first = 2;
        if (i > 0)
            pref[i].first += pref[i-1].first;
        pref[i].second = i;
    }
    pref[n] = pii(0, -1);
}

void BuildSt(int st[], int v, int tl, int tr) {
    if (tl ==tr)
        st[v] = -1e9;
    else {
        int tm = (tl + tr)/2;
        BuildSt(st, v*2+1, tl, tm);
        BuildSt(st, v*2+2, tm+1, tr);
        st[v] = max(st[v*2+1], st[v*2+2]);
    }
}

void UpdateSt(int st[], int v, int tl, int tr, int id, int val) {
    if (tl == tr)
        st[v] = max(val, st[v]);
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateSt(st, v*2+1, tl, tm, id, val);
        else
            UpdateSt(st, v*2+2, tm+1, tr, id, val);
        st[v] = max(st[v*2+1], st[v*2+2]);
    }
}

int MaxQuery(int st[], int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l) || (l > r))
        return -1e9;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = (tl + tr)/2;
    return (max(MaxQuery(st, v*2+1, tl, tm, l, r), MaxQuery(st, v*2+2, tm+1, tr, l, r)));
}

bool CmpPiiFirst(pii a, pii b) {
    if (a.first == b.first)
        return (a.second > b.second);
    return (a.first > b.first);
}

bool CmpPiiSecond(pii a, pii b) {
    return (a.second < b.second);
}

void Solve() {
    int MaxLen = 0, MaxCnt = 0;
    sort(pref, pref+n+1, CmpPiiFirst);
    for (int i=0; i<=n; i++) {
        int j = MaxQuery(stMax, 0, 0, MaxSum, pref[i].first + Base, MaxSum);
        MaxLen = max(MaxLen, j - pref[i].second);
        UpdateSt(stMax, 0, 0, MaxSum, pref[i].first + Base, pref[i].second);
    }
    if (MaxLen == 0) {
        cout << "No solution";
        return;
    }
    sort(pref, pref+n+1, CmpPiiSecond);
    for (int i=0; i+MaxLen-1<n; i++) {
        if (pref[i+MaxLen].first >= pref[i].first)
            MaxCnt++;
    }
    cout << MaxLen << ' ' << MaxCnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    BuildSt(stMax, 0, 0, MaxSum);
    cin >> s;
    n = s.length();
    MakePref();
    Solve();
    return 0;
}
