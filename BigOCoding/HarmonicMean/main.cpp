#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll S, n, a[9];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll LCM(ll a, ll b) {
    return ((a*b)/__gcd(a,b));
}

void SolveTestCase() {
    ll Sum = 0, LCMAll = a[1];
    for (int i=2; i<=n; i++)
        LCMAll = LCM(LCMAll, a[i]);
    for (int i=1; i<=n; i++)
        Sum += (LCMAll/a[i]);
    ll Tu = LCMAll * n, Mau = Sum;
    ll GCDTuMau = __gcd(Tu, Mau);
    Tu = Tu/GCDTuMau;
    Mau = Mau/GCDTuMau;
    cout << Tu << '/' << Mau << '\n';
}

void Solve() {
    for (int i=1; i<=S; i++) {
        cin >> n;
        ReadData();
        cout << "Case " << i << ": ";
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> S;
    Solve();
    return 0;
}
