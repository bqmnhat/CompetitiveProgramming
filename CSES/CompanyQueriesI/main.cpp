#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define MaxL 18
using namespace std;
int n, q, parent[MaxN+1][MaxL];

void ReadData() {
    parent[1][0] = -1;
    for (int i=2; i<=n; i++)
        cin >> parent[i][0];
}

void Preprocessing() {
    for (int j=1; j<MaxL; j++) {
        for (int i=1; i<=n; i++) {
            if (parent[i][j-1] != -1)
                parent[i][j] = parent[parent[i][j-1]][j-1];
            else
                parent[i][j] = -1;
        }
    }
}

int Query(int k, int x) {
    for (int i=MaxL-1; i>=0 && x!=-1; i--) {
        if ((1 << i) <= k) {
            x = parent[x][i];
            k -= (1 << i);
        }
    }
    return x;
}

void Solve() {
    int x, k;
    for (int i=1; i<=q; i++) {
        cin >> x >> k;
        cout << Query(k, x) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    Preprocessing();
    Solve();
    return 0;
}
