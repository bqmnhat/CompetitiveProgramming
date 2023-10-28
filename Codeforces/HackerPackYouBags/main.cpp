#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200010
using namespace std;
typedef long long ll;
int n, x;
ll MinCostLen[MaxN+1];
struct Pos {
    int pos, len, type; // type == 0 => l; type == 1 => r
    ll cost;
};
vector<Pos> Poss;
const ll INF = 1e18 + 7;

void ReadData() {
    int l, r, c;
    for (int i=1; i<=n; i++) {
        cin >> l >> r >> c;
        int length = r - l + 1;
        Poss.push_back({l, length, 0, c});
        Poss.push_back({r, length, 1, c});
    }
}

void Init() {
    for (int i=0; i<=MaxN; i++)
        MinCostLen[i] = INF;
}

bool CmpPos(Pos a, Pos b) {
    if (a.pos == b.pos)
        return (a.type < b.type);
    return (a.pos < b.pos);
}

ll Solution() {
    ll ans = INF;
    sort(Poss.begin(), Poss.end(), CmpPos);
    for (int i=0; i<Poss.size(); i++) {
        if ((Poss[i].type == 0) && (x - Poss[i].len >= 0)) {
            ll tmpans = Poss[i].cost + MinCostLen[x - Poss[i].len];
            ans = min(ans, tmpans);
        }
        else
            MinCostLen[Poss[i].len] = min(MinCostLen[Poss[i].len], Poss[i].cost);
    }
    if (ans >= INF)
        return -1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ReadData();
    Init();
    cout << Solution();
    return 0;
}
