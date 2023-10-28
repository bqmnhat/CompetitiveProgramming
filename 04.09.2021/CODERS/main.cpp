#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxN 200000
int n, p[MaxN+1], Q, a[MaxN], m1[MaxN], m2[MaxN], ml = 0;
long long la = -1, MaxId;

void ReadData() {
    int Max = 0;
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        if (p[i] > Max) {
            Max = p[i];
            MaxId = i;
        }
    }
}

void CompeteTillMax() {
    for (int i=MaxId+1; i<=n; i++) {
        la++;
        a[la] = p[i];
    }
    int t = 1, i = 1;
    while (t < MaxId) {
        i++;
        la++;
        ml++;
        m1[ml] = p[t];
        m2[ml] = p[i];
        if (p[i] > p[t]) {
            a[la] = p[t];
            t = i;
        }
        else
            a[la] = p[i];
    }
}

void Solve() {
    long long k;
    for (int i=1; i<=Q; i++) {
        cin >> k;
        if (k < MaxId)
            cout << m1[k] << " " << m2[k];
        else
            cout << p[MaxId] << " " << a[(k - MaxId)%(la + 1)];
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CODERS.INP", "r", stdin);
    freopen("CODERS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cin >> Q;
    CompeteTillMax();
    Solve();
    return 0;
}
