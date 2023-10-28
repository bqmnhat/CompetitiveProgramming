#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef long long ll;
int n, a[MaxN+1], freq[MaxN+1], lf = 0;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakeFreq() {
    sort(a+1, a+1+n);
    for (int i=1; i<=n; i++) {
        if (a[i] != a[lf])
            lf++;
        a[lf] = a[i];
        freq[lf]++;
    }
}

ll Solution() {
    ll ans = 0;
    for (int i=lf; i>=2; i--) {
        int lo = 1, hi = i-1;
        while (lo < hi) {
            if (a[lo] + a[hi] > a[i]) {
                ans += hi - lo;
                hi--;
            }
            else
                lo++;
        }
    }
    for (int i=1; i<=lf; i++) {
        for (int j=1; j<=lf; j++) {
            if (i == j)
                continue;
            if ((a[i] < 2*a[j]) && (freq[j] >= 2))
                ans++;
        }
        if (freq[i] >= 3)
            ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TRIANGLES.INP", "r", stdin);
    freopen("TRIANGLES.OUT", "w", stdout);
    cin >> n;
    ReadData();
    MakeFreq();
    cout << Solution();
    return 0;
}
