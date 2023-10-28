#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
typedef pair<int, int> pii;
int n, q, x, LeftLess[MaxN+1], RightLess[MaxN+1], a[MaxN+1], b[MaxN+1], ans[MaxN+1];
bool vis[MaxN+1];
pii k[MaxN+1];
vector<int> g[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=q; i++) {
        cin >> k[i].first;
        k[i].second = i;
    }
}

void FindLeftLess() {
    stack<pii> stk;
    for (int i=n; i>=1; i--) {
        while ((!stk.empty()) && (stk.top().first > a[i])) {
            int id = stk.top().second;
            stk.pop();
            LeftLess[id] = i;
        }
        stk.push(pii(a[i], i));
    }
}

void FindRightLess() {
    stack<pii> stk;
    for (int i=1; i<=n; i++) {
        while ((!stk.empty()) && (stk.top().first > a[i])) {
            int id = stk.top().second;
            stk.pop();
            RightLess[id] = i;
        }
        stk.push(pii(a[i], i));
    }
}

void MakeB() {
    for (int i=1; i<=n; i++) {
        if ((RightLess[i] == 0) && (LeftLess[i] == 0))
            continue;
        if (RightLess[i] == 0) {
            b[i] = LeftLess[i];
            continue;
        }
        if (LeftLess[i] == 0) {
            b[i] = RightLess[i];
            continue;
        }
        int DistLeft = abs(i - LeftLess[i]), DistRight = abs(i - RightLess[i]);
        if (DistLeft == DistRight) {
            if (a[LeftLess[i]] > a[RightLess[i]])
                b[i] = LeftLess[i];
            else
                b[i] = RightLess[i];
        }
        else if (DistLeft < DistRight)
            b[i] = LeftLess[i];
        else
            b[i] = RightLess[i];
    }
}

void MakeG() {
    for (int i=1; i<=n; i++)
        g[b[i]].push_back(i);
}

void Solve() {
    FindLeftLess();
    FindRightLess();
    MakeB();
    MakeG();
    sort(k+1, k+1+q);
    queue<int> Q;
    int cntnode = 0, time = 0;
    if (x > 0) {
        for (int i=1; i<=n; i++) {
            if (a[i] <= x) {
                vis[i] = true;
                Q.push(i);
                cntnode++;
            }
        }
        vis[0] = true;
    }
    else {
        Q.push(0);
        vis[0] = true;
    }
    int i = 1;
    while (!Q.empty()) {
        int sz = Q.size();
        while ((i <= q) && (k[i].first <= cntnode)) {
            ans[k[i].second] = time;
            i++;
        }
        while (sz--) {
            int u = Q.front();
            Q.pop();
            for (int v: g[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    cntnode++;
                    Q.push(v);
                }
            }
        }
        time++;
    }
    while ((i <= q) && (k[i].first <= cntnode)) {
        ans[k[i].second] = time;
        i++;
    }
    for (int i=1; i<=q; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q >> x;
    ReadData();
    Solve();
    return 0;
}
