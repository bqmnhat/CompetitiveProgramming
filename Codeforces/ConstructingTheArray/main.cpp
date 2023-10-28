#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int t, n, a[MaxN+1];

struct CustomCompare {
    bool operator() (const pii& a,const pii& b) {
        if ((a.second - a.first + 1) == (b.second - b.first + 1))
            return (a.first > b.first);
        return ((a.second - a.first + 1) < (b.second - b.first + 1));
    }
};

void SolveTestCase() {
    priority_queue<pii, vector<pii>, CustomCompare> pq;
    pq.push(pii(1, n));
    int cnt = 0;
    while ((!pq.empty()) && (cnt <= n)) {
        cnt++;
        pii tmp = pq.top();
        pq.pop();
        int ChangeId, len = tmp.second - tmp.first + 1;
        if (len%2)
            ChangeId = (tmp.first + tmp.second)/2;
        else
            ChangeId = (tmp.first + tmp.second - 1)/2;
        a[ChangeId] = cnt;
        if (tmp.first < ChangeId)
            pq.push(pii(tmp.first, ChangeId-1));
        if (tmp.second > ChangeId)
            pq.push(pii(ChangeId+1, tmp.second));
    }
    for (int i=1; i<=n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        SolveTestCase();
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
