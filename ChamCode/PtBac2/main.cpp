#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c;

void Solve() {
    if (a == b) {
        if (c == b)
            cout << "VSN";
        else
            cout << "VN";
        return;
    }
    double delta = (b*b) - 4*(a*c);
    if (delta < 0) {
        cout << "VN";
        return;
    }
    if (delta == 0) {
        cout << "x = 2.00";
        return;
    }
    double x1 = double(double(-b) + sqrt(delta))/double(2*double(a)), x2 = double(double(-b) - sqrt(delta))/double(2*double(a));
    cout << fixed << setprecision(2) << x1 << " " <<  x2;
}

int main()
{
    cin >> a >> b >> c;
    Solve();
    return 0;
}
