#include <iostream>
#include <bits/stdc++.h>
#define MaxN 400000
using namespace std;
typedef pair<int, int> pii;
int n, mark[MaxN+5];
pii PointOfTime[MaxN+5];
priority_queue<int, vector<int>, greater<int>> pq;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> PointOfTime[i*2].first >> PointOfTime[i*2 - 1].first;
        PointOfTime[i*2].second = -i;
        PointOfTime[i*2-1].second = i;
    }
}

void Solve() {
    sort(PointOfTime+1, PointOfTime+1+2*n);
    for (int i=1; i<=n; i++)
        pq.push(i);
    int cnt = 0;
    for (int i=1; i<=2*n; i++) {
        pii CurTime = PointOfTime[i];
        int id = abs(CurTime.second);
        if (CurTime.second < 0) {
            int Top = pq.top();
            pq.pop();
            mark[id] = Top;
            cnt = max(cnt, Top);
        }
        else
            pq.push(mark[id]);
    }
    cout << cnt << '\n';
    for (int i=1; i<=n; i++)
        cout << mark[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
