#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
int n;
ll x;
pii a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
}

int BinSearch(int lo, int hi, ll val) {
    int mid;
    while (lo <= hi) {
        mid = ((lo + hi) >> 1LL);
        if (a[mid].first == val)
            return mid;
        else if (a[mid].first > val)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return -1;
}

void Solve() {
    sort(a+1, a+1+n);
    for (int i=1; i<n; i++) {
        int tmp = BinSearch(i+1, n, x - a[i].first);
        if (tmp != -1) {
            cout << min(a[tmp].second, a[i].second) << ' ' << max(a[i].second, a[tmp].second);
            return;
        }
    }
    cout << "IMPOSSIBLE";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ReadData();
    Solve();
    return 0;
}
