#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100005
using namespace std;
typedef long long ll;
int n;
ll l[MaxN+1], r[MaxN+1], w[MaxN+1], h[MaxN+1], MinID = -1, res[MaxN+1], counter = 0;
const ll inf = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> w[i] >> h[i];
        if (MinID == -1)
            MinID = i;
        else if (h[i] < h[MinID])
            MinID = i;
    }
}

void Solve() {
    h[0] = inf;
    h[n+1] = inf;
    for (int i=1; i<=n; i++) {
        l[i] = i-1;
        r[i] = i+1;
    }
    int CurID = MinID;
    while (h[CurID] < inf) {
        res[CurID] = counter + w[CurID];
        r[l[CurID]] = r[CurID];
        l[r[CurID]] = l[CurID];
        if (h[r[CurID]] < h[l[CurID]]) {
            counter += (h[r[CurID]] - h[CurID])*w[CurID];
            w[r[CurID]] += w[CurID];
            do {
                CurID = r[CurID];
            } while (h[CurID] > h[r[CurID]]);
        }
        else {
            counter += (h[l[CurID]] - h[CurID])*w[CurID];
            w[l[CurID]] += w[CurID];
            do {
                CurID = l[CurID];
            } while (h[CurID] > h[l[CurID]]);
        }
    }
    for (int i=1; i<=n; i++)
        cout << res[i] << '\n';
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
