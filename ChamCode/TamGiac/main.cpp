#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;

bool IsTri(ll a, ll b, ll c) {
    if ((a + b > c) && (b + c > a) && (a + c > b))
        return true;
    else
        return false;
}

void Solve() {
    if (IsTri(a,b,c)) {
        ll chuvi = a + b + c;
        double p = double(chuvi)/2.0;
        double S = sqrt(p*(p - double(a))*(p - double(b))*(p - double(c)));
        cout << fixed << setprecision(2) << double(chuvi) << " " << S;
    }
    else
        cout << "NO";
}

int main()
{
    cin >> a >> b >> c;
    Solve();
    return 0;
}
