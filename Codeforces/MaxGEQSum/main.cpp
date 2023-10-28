#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, n;
ll a[MaxN+1], pref[MaxN+2], suf[MaxN+2], StPref[4*MaxN+1], StSuf[4*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

vector<int> NextGreater() {
    stack<int> stk;
    vector<int> res(n+1, n+1);
    for (int i=1; i<=n; i++) {
        while ((!stk.empty()) && (a[i] > a[stk.top()])) {
            res[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    return res;
}

vector<int> PreGreater() {
    stack<int> stk;
    vector<int> res(n+1, 0);
    for (int i=n; i>=1; i--) {
        while ((!stk.empty()) && (a[i] > a[stk.top()])) {
            res[stk.top()] = i;
            stk.pop();
        }
        stk.push(i);
    }
    return res;
}

void MakePrefAndSuf() {
    for (int i=1; i<=n; i++)
        pref[i] = pref[i-1] + a[i];
    for (int i=n; i>=1; i--)
        suf[i] = suf[i+1] + a[i];
}

void BuildSt(ll St[4*MaxN+1], ll arr[MaxN+2], int v, int tl, int tr) {
    if (tl == tr)
        St[v] = arr[tl];
    else {
        int tm = (tl + tr)/2;
        BuildSt(St, arr, v*2, tl, tm);
        BuildSt(St, arr, v*2+1, tm+1, tr);
        St[v] = max(St[v*2], St[v*2+1]);
    }
}

ll GetMax(ll St[4*MaxN+1], int v, int tl, int tr, int l ,int r) {
    if ((tl > r) || (tr < l))
        return -1e18;
    if ((tl >= l) && (r >= tr))
        return St[v];
    int tm = (tl + tr)/2;
    return max(GetMax(St, v*2, tl, tm, l, r), GetMax(St, v*2+1, tm+1, tr, l, r));
}

bool Solution() {
    vector<int> ng, pg;
    ng = NextGreater();
    pg = PreGreater();
    BuildSt(StPref, pref, 1, 1, n);
    BuildSt(StSuf, suf, 1, 1, n);
    for (int i=1; i<=n; i++) {
        ll MaxPref = GetMax(StPref, 1, 1, n, i+1, ng[i]-1) - pref[i];
        ll MaxSuf = GetMax(StSuf, 1, 1, n, pg[i]+1, i-1) - suf[i];
        if (max(MaxPref, MaxSuf) > 0)
            return false;
    }
    return true;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        MakePrefAndSuf();
        if (Solution())
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
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
