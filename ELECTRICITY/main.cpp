#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n,k,a[100001], ls = 0;
pii seg[100001];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> a[i];
}

void MakeSeg() {
    for (int i=0; i<n; i++) {
        if (a[i] == 0)
            continue;
        ls++;
        seg[ls].first = i - k + 1;
        seg[ls].second = i + k - 1;
    }
}

void Solve() {
    seg[++ls] = pii(100001, 100001);
    int r = -1, ans = 0;
    for (int i=1; i<=ls; i++) {
        if (seg[i].first > r + 1) {
            r = seg[i-1].second;
            ans++;
        }
        if (r >= n-1)
            break;
    }
    if (r < n-1)
        cout << "NO SOLUTION";
    else
        cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ELECTRICITY.INP", "r", stdin);
    freopen("ELECTRICITY.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    MakeSeg();
    Solve();
    return 0;
}
