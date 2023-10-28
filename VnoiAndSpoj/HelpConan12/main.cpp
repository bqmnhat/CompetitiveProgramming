#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int t, n;
ll a[MaxN+5];

void MakeA() {
    a[0] = 0;
    a[1] = 1;
    for (int i=2; i<=MaxN; i++) {
        if (i&1) {
            int i1 = i/2;
            int i2 = i - i1;
            a[i] = a[i1] + a[i2];
        }
        else
            a[i] = a[i/2];
    }
    ll Max = 0;
    for (int i=0; i<=MaxN; i++) {
        Max = max(a[i], Max);
        a[i] = Max;
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << a[n] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    MakeA();
    Solve();
    return 0;
}
