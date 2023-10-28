#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double p,q,r,s,t,u;
const double Erate = 1e-7;

double CalF(double x) {
    return (p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}

double FindX() { //Bisection method: f(x) continuous (non-increasing) on interval [0,1]
    double lo = 0, hi = 1;
    while (lo + Erate < hi) {
        double mid = (lo + hi)/2.00;
        if (CalF(lo) * CalF(mid) <= 0.00)
            hi = mid;
        else
            lo = mid;
    }
    return (lo + hi)/2.00;
}

void Solve() {
    while (cin >> p >> q >> r >> s >> t >> u) {
        if (CalF(0) * CalF(1) > 0)
            cout << "No solution\n";
        else
            cout << fixed << setprecision(4) << FindX() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("FLOAT.INP", "r", stdin);
    Solve();
    return 0;
}
