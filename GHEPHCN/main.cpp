#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,d;

void Solve() {
    int a,b;
    a = b = n/4;
    n = n%4;
    b = b + (n/2);
    cout << (a+b)*2 << endl;
    cout << a << endl;
    cout << b << endl;
    cout << a*b*d*d;
}

int main()
{
    freopen("GHEPHCN.INP", "r", stdin);
    freopen("GHEPHCN.OUT", "w", stdout);
    cin >> n >> d;
    Solve();
    return 0;
}
