#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int y,h,d,s[100001], k[100001], p[100001];

void ReadData() {
    for (int i=1; i<=d; i++)
        cin >> s[i] >> k[i] >> p[i];
}

int Solution() {
    vector<vector<pair<int,int>>> mark(11);
    for (int i=1; i<=d; i++)
        mark[k[i]].push_back({s[i], p[i]});
    vector<int> vis(h+1);
    for (int k=2; k<=10; k++) {
        vector<int> cnt(h+1);
        for (auto tmp: mark[k]) {
            cnt[tmp.first]++;
            int LastPlus = min(h+1, tmp.first + tmp.second*k);
            if (LastPlus <= h)
                cnt[LastPlus]--;
        }
        for (int i=1; i<=h; i++) {
            if (i > k)
                cnt[i] += cnt[i-k];
            vis[i] += cnt[i];
        }
    }
    int MaxCnt = 0, MaxId;
    for (int i=1; i<=h; i++) {
        if (vis[i] > MaxCnt) {
            MaxCnt = vis[i];
            MaxId = i;
        }
    }
    return MaxId;
}

void Solve() {
    for (int i=1; i<=y; i++) {
        cin >> h >> d;
        ReadData();
        cout << "House " << Solution() << " should get the biggest and best gift next Christmas.\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> y;
    Solve();
    return 0;
}
