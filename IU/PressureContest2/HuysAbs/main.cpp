#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int t, n, k;
ll a[MaxN+2];

void ReadData() {
    n++;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    a[0] = 0;
}

int BinSearchLower(int lo, int hi, ll val) {
    int mid, ans = -1;
    while (lo <= hi) {
        mid = ((lo + hi)>>1);
        if (a[mid] <= val) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

ll Solution() {
    int i=0;
    ll ans = 0;
    while (i < n) {
        int tmp = BinSearchLower(i+1, n, a[i] + k);
        if (tmp == -1)
            return -1;
        i = tmp;
        ans++;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
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
