#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;

int main()
{
    cin >> a >> b;
    cout << a + b << " " << a - b << '\n';
    cout << a*b << " " << setprecision(2) << fixed << double(double(a)/double(b));
    return 0;
}
