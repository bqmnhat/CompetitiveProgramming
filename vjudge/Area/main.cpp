#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
ll L;
int t;
const ld Pi = acos(-1);

void SolveTestCase() {
    ld W = (ld(L)*6.00)/10.00;
    ld r = ld(L)/5.00;
    ld ansCir = Pi*(r*r);
    ld ansRec = (ld(L)*W) - ansCir;
    cout << setprecision(2) << fixed << ansCir << ' ' << ansRec << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> L;
        SolveTestCase();
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
