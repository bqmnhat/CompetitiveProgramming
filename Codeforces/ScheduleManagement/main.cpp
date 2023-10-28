#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
ll cnt[MaxN+1];
int n, t, m;

void InitCnt() {
    for (int i=1; i<=n; i++)
        cnt[i] = 0;
}

void CntData() {
    int ai;
    for (int i=1; i<=m; i++) {
        cin >> ai;
        cnt[ai]++;
    }
}

bool Check(ll Time) {
    ll Left = 0;
    for (int i=1; i<=n; i++)
        Left += max(0LL, cnt[i] - Time);
    for (int i=1; i<=n; i++)
        Left = Left - max(0LL, (Time - cnt[i])/2);
    if (Left > 0)
        return false;
    return true;
}

ll Solution() {
    int lo = 1, hi = 2*MaxN, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (Check(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        InitCnt();
        CntData();
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
