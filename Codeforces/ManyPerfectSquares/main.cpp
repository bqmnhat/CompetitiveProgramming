#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
typedef unsigned long long ll;
int t, n;
ll a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

bool IsSquare(ll val) {
    ll tmp = sqrt(val);
    return (tmp*tmp == val);
}

int Solution() {
    int ans = 1;
    for (int i=1; i<=n; i++) {
        for (int j = i+1; j<=n; j++) {
            ll Dist = a[j] - a[i];
            for (ll val = 1; val*val <= Dist; val++) {
                if (Dist%val != 0)
                    continue;
                ll q = (Dist/val - val);
                if (q%2 == 0) {
                    q >>= 1LL;
                    if (q*q < a[i])
                        continue;
                    ll x = q*q - a[i];
                    int tmpans = 0;
                    for (int i=1; i<=n; i++)
                        if (IsSquare(a[i] + x))
                            tmpans++;
                    ans = max(ans, tmpans);
                }
            }
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
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
