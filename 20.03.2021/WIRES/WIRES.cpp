#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[100001], sum = 0;
int n,k;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum+=a[i];
    }
}

long long NOfSeg(int l) {
    long long ans = 0;
    for (int i=1; i<=n; i++) {
        ans += a[i]/l;
    }
    return ans;
}

long long MaxLength() {
    long long lo = 1, hi = sum, ans = 0;
    while (lo <= hi) {
        long long L = (lo + hi)/2;
        if (NOfSeg(L) >= k) {
            ans = L;
            lo = L+1;
        }
        else
            hi = L-1;
    }
    return ans;
}

void Solve() {
    while (cin >> n >> k) {
        ReadData();
        cout << MaxLength();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("WIRES.INP", "r", stdin);
    freopen("WIRES.OUT", "w", stdout);
    Solve();
    return 0;
}
