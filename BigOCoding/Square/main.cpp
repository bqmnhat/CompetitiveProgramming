#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20
using namespace std;
typedef long long ll;
int t, n;
ll a[MaxN+1], sum, SumOfMask[(1 << MaxN)];
bool dp[(1 << MaxN)];

void ReadData() {
    sum = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

bool Solution() {
    if (sum%4 != 0)
        return false;
    memset(dp, false, sizeof(dp));
    memset(SumOfMask, 0, sizeof(SumOfMask));
    dp[0] = true;
    ll edgelen = sum/4;
    for (int mask = 1; mask < (1 << n); mask++)
        for (int i=0; i<n; i++)
            if (mask & (1 << i))
                SumOfMask[mask] += a[i];
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i=0; i<n; i++) {
            if (mask & (1 << i)) {
                int Submask = (mask ^ (1 << i));
                if ((dp[Submask]) && (SumOfMask[Submask]%edgelen + a[i] <= edgelen)) {
                    dp[mask] = true;
                    break;
                }
            }
        }
    }
    return (dp[(1 << n) - 1]);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        if (Solution())
            cout << "yes";
        else
            cout << "no";
        cout << '\n';
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
