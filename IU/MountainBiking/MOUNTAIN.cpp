#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, g;
ll d[5], phi[5];
const ld PI = 3.1415926535897932384626433832795;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> d[i] >> phi[i];
}

ld CalT(ld v0, ll g, ll phi, ll dist) {
    ld delta = (v0*v0) + ld(2.0*ld(g)*cos(phi*(PI/180))*dist);
    ld ans = ld(-v0 + sqrt(delta))/(g*cos(phi*(PI/180)));
    return ans;
}

ld Solution(int x) {
    ld v = 0.0, NewV = 0.0;
    for (int i=x; i<=n; i++) {
        ld NewT = CalT(v, g, phi[i], d[i]);
        NewV = v + (ld)g*cos(phi[i]*(PI/180))*NewT;
        v = NewV;
    }
    return v;
}

void Solve() {
    for (int i=1; i<=n; i++)
        cout << setprecision(14) << fixed << Solution(i) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MOUNTAIN.INP", "r", stdin);
    freopen("MOUNTAIN.OUT", "w", stdout);
    cin >> n >> g;
    ReadData();
    Solve();
    return 0;
}
