#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
long long x,y,a,b,k;

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> x >> y >> a >> b >> k;
        long long tmp1 = x + (a*k), tmp2 = y + (b*k);
        if (tmp1 == tmp2)
            cout << "SAME PRICE";
        else if (tmp1 < tmp2)
            cout << "PETROL";
        else
            cout << "DIESEL";
        cout << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
