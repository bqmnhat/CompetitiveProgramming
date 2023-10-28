#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int n, q, Max = 0, lpc = 0, lc = 0;
ll m;
pii preCycle[MaxN+1], Cycle[MaxN+1];
deque<int> dq;

void ReadData() {
    int ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        Max = max(Max, ai);
        dq.push_back(ai);
    }
}

void MakeCycle() {
    while (dq.front() != Max) {
        int tmp1 = dq.front();
        dq.pop_front();
        int tmp2 = dq.front();
        dq.pop_front();
        lpc++;
        preCycle[lpc] = pii(tmp1, tmp2);
        dq.push_front(max(tmp1, tmp2));
        dq.push_back(min(tmp1, tmp2));
    }
    for (int i=1; i<n; i++) {
        lc++;
        Cycle[lc] = pii(dq[0], dq[i]);
    }
}

void Solve() {
    for (int i=1; i<=q; i++) {
        cin >> m;
        if (m <= lpc)
            cout << preCycle[m].first << ' ' << preCycle[m].second;
        else {
            m = m - lpc;
            m = m%lc;
            if (m == 0)
                m = lc;
            cout << Cycle[m].first << ' ' << Cycle[m].second;
        }
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    MakeCycle();
    Solve();
    return 0;
}
