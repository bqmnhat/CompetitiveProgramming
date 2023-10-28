#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, p[100001];
bool vis[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> p[i];
}

void Init() {
    for (int i=1; i<=n; i++)
        vis[i] = false;
}

int Solution() {
    int ans = 0, MaxNow = 1, MaxVis = 1;
    for (int i=1; i<=n; i++) {
        if (p[i] > MaxNow) {
            vis[p[i]] = true;
            MaxNow = p[i];
        }
        else {
            vis[p[i]] = true;
            while ((MaxVis <= n) && (vis[MaxVis]))
                MaxVis++;
            if (MaxVis > MaxNow) {
                MaxNow = MaxVis;
                ans++;
            }
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        Init();
        cout << Solution() << '\n';
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
