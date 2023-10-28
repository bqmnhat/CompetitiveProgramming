#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int t, n, k, a[MaxN+1], NewA[MaxN+1], ForSort[MaxN+1], MinID[MaxN+1], MaxID[MaxN+1];
map<int, int> ma;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        ForSort[i] = a[i];
    }
}

void Mapping() {
    sort(ForSort+1, ForSort+1+n);
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (ma.find(ForSort[i]) == ma.end()) {
            cnt++;
            ma[ForSort[i]] = cnt;
        }
    }
}

void MakeNewA() {
    for (int i=1; i<=n; i++)
        NewA[i] = ma[a[i]];
}

void FindMaxAndMinID() {
    for (int i=n; i>=1; i--)
        MinID[NewA[i]] = i;
    for (int i=1; i<=n; i++)
        MaxID[NewA[i]] = i;
}

void InitMinAndMaxID() {
    for (int i=0; i<=n; i++)
        MinID[i] = MaxID[i] = -1;
}

void SolveTestCase() {
    for (int i=1; i<=k; i++) {
        int ai, bi;
        cin >> ai >> bi;
        int MappedAi = ma[ai], MappedBi = ma[bi];
        if ((MinID[MappedAi] == -1) || (MaxID[MappedBi] == -1)) {
            cout << "NO\n";
            continue;
        }
        if ((MinID[MappedAi] < MaxID[MappedBi]) || (MappedAi == MappedBi))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        if (i == 1)
            InitMinAndMaxID();
        ma.clear();
        ReadData();
        Mapping();
        MakeNewA();
        FindMaxAndMinID();
        SolveTestCase();
        InitMinAndMaxID();
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
