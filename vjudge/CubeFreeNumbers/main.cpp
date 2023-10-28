#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int t, n, d[MaxN+5], PosOfCubeFree[MaxN+5];

void MakeSieve() {
    for (int i=2; i*i<=MaxN; i++)
        if (d[i] == 0)
            for (int j=i; i*j<=MaxN; j++)
                d[i*j] = i;
}

bool CheckCubeFree(ll val) {
    unordered_map<ll, int> cnte;
    cnte.clear();
    while (val > 1) {
        ll p = d[val];
        if (p == 0)
            p = val;
        cnte[p]++;
        if (cnte[p] >= 3)
            return false;
        val /= p;
    }
    return true;
}

void CheckAllCubeFree() {
    int cnt = 0;
    for (int i=1; i<=MaxN; i++) {
        if (CheckCubeFree(i)) {
            cnt++;
            PosOfCubeFree[i] = cnt;
        }
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << "Case " << i << ": ";
        if (!PosOfCubeFree[n])
            cout << "Not Cube Free";
        else
            cout << PosOfCubeFree[n];
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    CheckAllCubeFree();
    cin >> t;
    Solve();
    return 0;
}
