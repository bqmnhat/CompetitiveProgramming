#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
struct Time {
    int t, id, st;
} a[2*MaxN+1];
int n, m, la = 0;

void ReadData() {
    int li, ri;
    for (int  i=1; i<=n; i++) {
        cin >> li >> ri;
        la++;
        a[la] = {li, i, 0};
        la++;
        a[la] = {ri, i, 1};
    }
}

bool CmpTime(Time a, Time b) {
    if (a.t == b.t)
        return (a.st < b.st);
    return (a.t < b.t);
}

void Solve() {
    sort(a+1, a+1+2*n, CmpTime);
    for (int i=2; i<=2*n; i++){
        if ((a[i].t > a[i-1].t) && (a[i].st == 0) && (a[i-1].st != a[i].st)) {
            cout << "YES\n" << a[i-1].id << ' ' << a[i].id;
            return;
        }
    }
    cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
