#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pii;
int n;
long long a[100001], sum[100002], lb = 0;
pii b[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakeSum() {
    for (int i=n; i>=1; i--)
        sum[i] = sum[i+1] + a[i];
}

int BinSearch(long long val) {
    int lo = 1, hi = lb, ans = -1;
    while (lo <= hi) {
        int m = ((lo + hi) >> 1);
        if (b[m].first - val > 0) {
            ans = b[m].second;
            hi = m - 1;
        }
        else
            lo = m + 1;
    }
    return ans;
}

void Solve() {
    int L, R, MaxLen = 0;
    for (int i=1; i<=n; i++) {
        if ((lb == 0) || (sum[i] >= b[lb].first)) {
            lb++;
            b[lb].first = sum[i];
            b[lb].second = i;
        }
        int x = BinSearch(sum[i+1]);
        if ((x != -1) && (i - x + 1 > MaxLen)) {
            L = x;
            R = i;
            MaxLen = i - x + 1;
        }
    }
    cout << L << ' ' << R;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PS.INP", "r", stdin);
    freopen("PS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    MakeSum();
    Solve();
    return 0;
}
