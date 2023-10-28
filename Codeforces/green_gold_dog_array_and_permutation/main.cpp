#include <iostream>
#include <bits/stdc++.h>
#define MaxN 40000
using namespace std;
typedef long long ll;
struct Data {
    ll val, b;
    int id;
};
int t, n;
Data a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].val;
        a[i].id = i;
    }
}

bool CmpVal(Data a, Data b) {
    return a.val < b.val;
}

bool CmpId(Data a, Data b) {
    return a.id < b.id;
}

void SolveTestCase() {
    sort(a+1, a+1+n, CmpVal);
    for (int i=1; i<=n; i++)
        a[i].b = n+1-i;
    sort(a+1, a+1+n, CmpId);
    for (int i=1; i<=n; i++)
        cout << a[i].b << ' ';
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        SolveTestCase();
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
