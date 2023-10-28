#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, k;
ll a[MaxN+1], Sum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        Sum += a[i];
    }
}

bool Check(ll Mid, int k) {
    ll GrSum = 0;
    int GrCnt = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] > Mid)
            return false;
        GrSum += a[i];
        if (GrSum > Mid) {
            GrCnt++;
            GrSum = a[i];
        }
    }
    GrCnt++;
    return (GrCnt <= k);
}

ll BinSearchAns() {
    ll lo = 1, hi = Sum, mid, ans = -1;
    while (lo <= hi) {
        mid = (lo + hi)/2;
        if (Check(mid, k)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << BinSearchAns();
    return 0;
}
