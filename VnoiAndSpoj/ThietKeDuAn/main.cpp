#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int n;
map<int, vector<pii>> ma;
ll dp[MaxN+5][2];

void ReadData() {
    for (int i=1; i<=n; i++) {
        int xi, yi;
        cin >> xi >> yi;
        ma[max(xi, yi)].push_back(pii(xi, yi));
    }
}

bool Cmp(const pii& a, const pii& b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int cost(const pii& a, const pii& b) {
    return (abs(a.first - b.first) + abs(a.second - b.second));
}

void Solve() {
    ma[0].push_back(pii(0,0));
    int pre = 0, lvlCnt = 0;
    for (auto& [level, mems]: ma) {
        sort(mems.begin(), mems.end(), Cmp);
        ++lvlCnt;
        dp[lvlCnt][0] = min(dp[lvlCnt-1][0] + cost(ma[pre][0], mems.back()),
                        dp[lvlCnt-1][1] + cost(ma[pre].back(), mems.back()))
                        + cost(mems.back(), mems[0]);
        dp[lvlCnt][1] = min(dp[lvlCnt-1][0] + cost(ma[pre][0], mems[0]),
                        dp[lvlCnt-1][1] + cost(ma[pre].back(), mems[0]))
                        + cost(mems.back(), mems[0]);
        pre = level;
    }
    cout << min(dp[lvlCnt][0], dp[lvlCnt][1]);
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
