#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
bool vis[MaxN+1];
int t, n;

void InitVis() {
    for (int i=1; i<=n; i++)
        vis[i] = false;
}

void SolveTestCase() {
    InitVis();
    cout << 2 << '\n';
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (vis[i])
            continue;
        cout << i << ' ';
        vis[i] = true;
        cnt++;
        int tmp = 2;
        while (i*tmp <= n) {
            if (!vis[i*tmp]) {
                vis[i*tmp] = true;
                cout << i*tmp << ' ';
                cnt++;
            }
            tmp *= 2;
        }
        if (cnt == n)
            break;
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        SolveTestCase();
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
