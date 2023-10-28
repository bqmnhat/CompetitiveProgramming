#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x,d,dx,dd;

void Solve() {
    int nx, nd;
    nx = nd = min(x,d); // do de dam bao tinh xen ke mau cua hcn
    int t = 2*nd; // t la chu vi cua hcn
    if (dx == dd) {
        int a = t/4, b = t/4 + ((t%4)/2); // a = nx/4 + nd/4, b = a + (tong so doan du moi loai con lai)/2
        long long s = a*b*dx*dd;
        cout << nx << '\n' << nd << '\n' << s;
    }
    else {
        int a,b;
        a = b = t/4;
        long long s;
        if ((a%2 == 0) && (b%2 == 0)) {
            s = ((a/2)*(dx + dd))*((a/2)*(dx + dd));
        }
        else {
            if (t%4 != 0) {
                nx = nx - 1;
                nd = nx;
            }
            int k = (a/2)*(dx+dd);
            s = (k+dd)*(k+dx);
        }
        cout << nx << '\n' << nd << '\n' << s;
    }
}

int main()
{
    freopen("XANHDO.INP", "r", stdin);
    freopen("XANHDO.OUT", "w", stdout);
    cin >> x >> dx >> d >> dd;
    Solve();
    return 0;
}
