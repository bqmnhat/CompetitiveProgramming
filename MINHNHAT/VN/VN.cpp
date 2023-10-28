#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b) {
    int tmp = 0;
    while (b != 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

void Solve(int n, int m, int &x, int &a, int &b) {
    x = GCD(n,m);
    a = n/x;
    b = m/x;
}

int main()
{
    int n,m,x,a,b;
    freopen("VN.INP", "r", stdin);
    freopen("VN.OUT", "w", stdout);
    cin >> n >> m;
    Solve(n,m,x,a,b);
    cout << x << endl;
    cout << a << " " << b;
    return 0;
}
