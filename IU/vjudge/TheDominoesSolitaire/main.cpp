#include <iostream>
#include <bits/stdc++.h>
#define MaxM 50
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
pii d[MaxM+1];
ll st1, st2, fi1, fi2;
int n, m;
bool vis[MaxM+1], ans;

void ReadData() {
    for (int i=1; i<=m; i++) {
        cin >> d[i].first >> d[i].second;
        vis[i] = false;
    }
}

void BackTracking(ll last, int cnt) {
    if (cnt == n) {
        if (last == fi1)
            ans = true;
        return;
    }
    for (int i=1; i<=m; i++) {
        pii tmp = d[i];
        if (!vis[i]) {
            if (last == tmp.first) {
                vis[i] = true;
                BackTracking(tmp.second, cnt+1);
                vis[i] = false;
            }
            if (last == tmp.second) {
                vis[i] = true;
                BackTracking(tmp.first, cnt+1);
                vis[i] = false;
            }
        }
    }
}

bool CanFillSpaces() {
    ans = false;
    BackTracking(st2, 0);
    return ans;
}

void Solve() {
    while ((cin >> n) && (n != 0)) {
        cin >> m >> st1 >> st2 >> fi1 >> fi2;
        ReadData();
        if (CanFillSpaces())
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
