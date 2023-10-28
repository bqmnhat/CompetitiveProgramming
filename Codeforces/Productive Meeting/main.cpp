#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n, ans1[200001], ans2[200001], ans = 0;
priority_queue <pair <int, int>> q;

void ReadData() {
    int ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        q.push(make_pair(ai, i));
    }
}

void InitQ() {
    while (!q.empty())
        q.pop();
}

void PrintAns(int k) {
    for (int i=1; i<=k; i++)
        cout << ans2[i] << " " << ans1[i] << '\n';
}

void Solve() {
    while (q.top().first != 0) {
        int x = q.top().first, xid = q.top().second;
        q.pop();
        int y = q.top().first, yid = q.top().second;
        q.pop();
        if ((x == 0) || (y == 0))
            break;
        ans++;
        ans1[ans] = xid;
        ans2[ans] = yid;
        q.push(make_pair(x-1, xid));
        q.push(make_pair(y-1, yid));
    }
    cout << ans << '\n';
    PrintAns(ans);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        InitQ();
        ans = 0;
        ReadData();
        Solve();
    }
    return 0;
}
