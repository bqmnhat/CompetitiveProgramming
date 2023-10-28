#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50000
#define MaxL 20
using namespace std;
int n, parent[MaxN+1][MaxL];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> parent[i][0];
}

void Preprocessing() {
    for (int j=1; j<MaxL; j++) {
        for (int i=0; i<n; i++) {
            if (parent[i][j-1] != -1)
                parent[i][j] = parent[parent[i][j-1]][j-1];
            else
                parent[i][j] = -1;
        }
    }
}

int Query(int x, int k) {
    for (int i=MaxL-1; i>=0 && x!=-1; i--) {
        if ((1 << i) <= k) {
            x = parent[x][i];
            k -= (1 << i);
        }
    }
    return x;
}

void Solve() {
    int k, x;
    while (cin >> x >> k)
        cout << Query(x, k) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Preprocessing();
    Solve();
    return 0;
}
