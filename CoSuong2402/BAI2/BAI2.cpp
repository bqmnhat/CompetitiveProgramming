#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
typedef long long ll;
int n;
ll a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    ll ans = 0;
    sort(a+1, a+1+n);
    int t;
    for (int i=1; i<=n-2; i++) {
        t = i+2;
        for(int j=i+1; j<=n; j++) {
            while ((t <= n) && (a[i] + a[j] > a[t]))
                t++;
            if (t > j)
                ans += (1LL*t - 1LL*j - 1LL);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
