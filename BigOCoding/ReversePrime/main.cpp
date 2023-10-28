#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000000
using namespace std;
typedef long long ll;
ll Sieve[MaxN+1], stCnt[4*MaxN+1], stSum[4*MaxN+1], RevPrimes[MaxN+1], rvSum[MaxN+1];
int lrp = 0;

void MakeSieve() {
    Sieve[0] = Sieve[1] = -1;
    for (int i=2; i*i<MaxN; i++)
        if (Sieve[i] == 0)
            for (int j=i; i*j<MaxN; j++)
                Sieve[i*j] = i;
}

int RevNum(int num) {
    int ans = 0;
    while (num > 0) {
        ans = ans*10 + num%10;
        num = num/10;
    }
    return ans;
}

int CountFactor(int val) {
    int ans = 0;
    while (val > 1) {
        int p = Sieve[val];
        if (p == 0)
            p = val;
        ans++;
        val = val/p;
    }
    return ans;
}

void FindRevPrimes() {
    for (int i=1e6; i<MaxN; i++) {
        int Num = RevNum(i);
        if ((Num < 1e6) && (Sieve[Num] == 0)) {
            lrp++;
            RevPrimes[lrp] = i;
            rvSum[lrp] = CountFactor(i);
        }
    }
}

void BuildSt(ll st[], int v, int tl, int tr, int val) { // -1 is turning counting mode off
    if (tl == tr) {
        if (val != -1)
            st[v] = val;
        else
            st[v] = rvSum[tl];
    }
    else {
        int tm = (tl + tr)/2;
        BuildSt(st, v*2, tl, tm, val);
        BuildSt(st, v*2+1, tm+1, tr, val);
        st[v] = st[v*2] + st[v*2+1];
    }
}

void UpdateSt(ll st[], int v, int tl, int tr, int id, ll val) {
    if (tl == tr)
        st[v] = val;
    else {
        int tm = (tl + tr)/2;
        if (id <= tm)
            UpdateSt(st, v*2, tl, tm, id, val);
        else
            UpdateSt(st, v*2+1, tm+1, tr, id, val);
        st[v] = st[v*2] + st[v*2+1];
    }
}

ll SumQuery(ll st[], int v, int tl, int tr, int l, int r) {
    if ((tl > r) || (tr < l))
        return 0;
    if ((l <= tl) && (tr <= r))
        return st[v];
    int tm = (tl + tr)/2;
    return (SumQuery(st, v*2, tl, tm, l, r) + SumQuery(st, v*2+1, tm+1, tr, l, r));
}

int BinSearchTruePos(ll val) {
    int lo = 1, hi = lrp, mid;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        ll tmp = SumQuery(stCnt, 1, 1, lrp, 1, mid);
        if (tmp == val)
            return mid;
        else if (tmp < val)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int BinSearchNumId(ll Num) {
    int lo = 1, hi = lrp, mid;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        if (RevPrimes[mid] == Num)
            return mid;
        else if (RevPrimes[mid] < Num)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

void Solve() {
    BuildSt(stSum, 1, 1, lrp, -1);
    BuildSt(stCnt, 1, 1, lrp, 1);
    char cmd;
    while (cin >> cmd) {
        if (cmd == 'q') {
            int id;
            cin >> id;
            id++;
            int TrueId = BinSearchTruePos(id);
            cout << SumQuery(stSum, 1, 1, lrp, 1, TrueId) << '\n';
        }
        else {
            ll Num;
            cin >> Num;
            int NumId = BinSearchNumId(Num);
            UpdateSt(stCnt, 1, 1, lrp, NumId, 0);
            UpdateSt(stSum, 1, 1, lrp, NumId, 0);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("REVPRIMES.INP", "r", stdin);
    MakeSieve();
    FindRevPrimes();
    Solve();
    return 0;
}
