#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
typedef long double ld;
int t, n;
ll a[MaxN+5], b[MaxN+5];

void SolveTestCase2() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        cin >> b[i];
    for (int i=1; i<=n; i++) {
        if (a[i] >= b[i])
            a[i+1] += (a[i] - b[i])/2;
        else {
            int j = 1;
            ll Cur = a[i] - b[i];
            while ((i+j<=n) && (Cur < 0)) {
                Cur += a[i+j]*((1LL << j));
                a[i+j] = 0;
                j++;
            }
            if ((i+j > n) && (Cur < 0)) {
                cout << "NO" << '\n';
                return;
            }
            a[i+1] += Cur/2;
        }
    }
    cout << "YES" << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        SolveTestCase2();
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
