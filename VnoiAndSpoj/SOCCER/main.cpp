#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200
using namespace std;
typedef pair<int, int> pii;
int n, m, power[2*MaxN+1][2*MaxN+1];

void ReadData() {
    int u, v, w;
    for (int i=1; i<=m; i++) {
        cin >> u >> v >> w;
        power[u][v] = power[v][u] = w;
    }
}

int Solution() {
    int ans = 1e9 + 7;
    for (int mask = 0; mask < (1 << (2*n)); mask++) {
        if (n == __builtin_popcount(mask)) {
            vector<int> tmp1, tmp2;
            tmp1.clear();
            tmp2.clear();
            int tmpmask = mask, cnt = 0, Power1 = 0, Power2 = 0;
            while (tmpmask > 0) {
                cnt++;
                int bit = (tmpmask&1);
                if (bit == 0) {
                    for (int x: tmp2)
                        Power2 += power[cnt][x];
                    tmp2.push_back(cnt);
                }
                else {
                    for (int x: tmp1)
                        Power1 += power[cnt][x];
                    tmp1.push_back(cnt);
                }
                tmpmask >>= 1;
            }
            while (cnt < 2*n) {
                cnt++;
                for (int x: tmp2)
                    Power2 += power[cnt][x];
                tmp2.push_back(cnt);
            }
            ans = min(ans, abs(Power1 - Power2));
            if (ans == 0)
                cout << "a";
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
