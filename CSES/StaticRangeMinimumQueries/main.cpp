#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200010
using namespace std;
typedef long long ll;
int n, q;
ll SpTabMin[MaxN+1][20], log_2[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> SpTabMin[i][0];
}

void CalculateLog2() {
    log_2[0] = log_2[1] = 0;
    for (int i=2; i<=MaxN; i++)
        log_2[i] = log_2[i/2] + 1;
}

void Preprocess() {
    int step;
    for (int j = 1; (1 << j) <= n+1; j++) {
        step = (1 << (j-1));
        for (int i=1; i + 2*step <= n+1; i++)
            SpTabMin[i][j] = min(SpTabMin[i][j-1], SpTabMin[i + step][j-1]);
    }
}

ll MinQuery(int l, int r) {
    int k = log_2[r - l + 1];
    return min(SpTabMin[l][k], SpTabMin[r - (1 << k) + 1][k]);
}

void Solve() {
    int u, v;
    Preprocess();
    for (int i=1; i<=q; i++) {
        cin >> u >> v;
        cout << MinQuery(u, v) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    CalculateLog2();
    cin >> n >> q;
    ReadData();
    Solve();
    return 0;
}
