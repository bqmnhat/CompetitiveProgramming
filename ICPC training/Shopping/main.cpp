#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n,m;
pii seg[501];

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> seg[i].first >> seg[i].second;
}

int Solution() {
    int ans = n+1, l = 0, r = 0;
    sort(seg+1, seg+1+m);
    for (int i=1; i<=m; i++) {
        if (seg[i].first <= r)
            r = max(r, seg[i].second);
        else {
            ans += ((r - l)*2);
            l = seg[i].first;
            r = seg[i].second;
        }
    }
    ans += ((r-l)*2);
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
