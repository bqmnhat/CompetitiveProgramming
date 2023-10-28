#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
int t, n, c, cnt[MaxN+1];

void InitCnt() {
    for (int i=1; i<=MaxN; i++)
        cnt[i] = 0;
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        int ai;
        cin >> ai;
        cnt[ai]++;
    }
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=MaxN; i++)
        ans += min(cnt[i], c);
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        InitCnt();
        cin >> n >> c;
        ReadData();
        cout << Solution() << '\n';
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
