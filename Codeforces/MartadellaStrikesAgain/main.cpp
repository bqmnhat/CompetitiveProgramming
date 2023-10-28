#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int t;
ld R, r;
const ld pi = acos(-1);

int Solution() {
    ld Area1 = R*R*pi, Area2 = pi*r*r*2.0;
    if (Area1 > Area2)
        return 1;
    else
        return 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> R >> r;
        cout << Solution() << '\n';
    }
    return 0;
}
