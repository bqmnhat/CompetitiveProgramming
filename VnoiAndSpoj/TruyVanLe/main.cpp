#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t, n, q;
vector<int> cntStart[MaxN+5], cntEnd[MaxN+5];
vector<bitset<MaxN>> Bits;
bitset<MaxN> tmp;
bitset<MaxN> InitBS(0);

void ReadData() {
    for (int i=1; i<=n; i++) {
        int a1, a2;
        cin >> a1 >> a2;
        cntStart[a1].push_back(i);
        cntEnd[a2+1].push_back(i);
    }
}

void Reset() {
    Bits.clear();
    Bits.push_back(InitBS);
    for (int i=1; i<=n; i++) {
        cntStart[i].clear();
        cntEnd[i].clear();
        Bits.push_back(InitBS);
    }
}

void Solve() {
    for (int cntt = 1; cntt <= t; cntt++) {
        cin >> n;
        Reset();
        ReadData();
        tmp.reset();
        for (int i=1; i<=n; i++) {
            for (int j = 0; j<cntStart[i].size(); j++)
                tmp.set(cntStart[i][j]);
            for (int j2 = 0; j2<cntEnd[i].size(); j2++)
                tmp.set(cntEnd[i][j2], 0);
            Bits[i] = tmp;
        }
        cin >> q;
        for (int cntq=1; cntq<=q; cntq++) {
            int m;
            cin >> m;
            tmp.reset();
            for (int i=1; i<=m; i++) {
                int Point;
                cin >> Point;
                tmp ^= Bits[Point];
            }
            cout << tmp.count() << '\n';
        }
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
