#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, dp[30001], MaxCost[30001], Cost[30001], tail[30001];
struct Segment {
    int a, b, c;
} x[30001];

bool CmpSegment(Segment a, Segment b) {
    return (a.b < b.b);
}

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i].a >> x[i].b >> x[i].c;
}

int BinSearch(int lo, int hi, int val) {
    int ans = 0;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (tail[m] <= val) {
            ans = m;
            lo = m + 1;
        }
        else
            hi = m - 1;
    }
    return ans;
}

int Solution() {
    sort(x+1, x+1+n, CmpSegment);
    for (int i=1; i<=n; i++) {
        int tmp = BinSearch(1, i-1, x[i].a);
        tail[i] = x[i].b;
        Cost[i] = x[i].c + MaxCost[tmp];
        MaxCost[i] = max(Cost[i], MaxCost[i-1]);
    }
    return MaxCost[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("WISCHEDULE.INP", "r", stdin);
    freopen("WISCHEDULE.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
