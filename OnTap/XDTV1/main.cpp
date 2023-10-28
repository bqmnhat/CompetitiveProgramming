#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x,dx,d,dd,t,dt,v,dv;

int GCD(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

int CalLength(int a, int da, int b, int db) {
    int bcnn = da*db / GCD(da,db);
    int ans = (min(a*da, b*db)/bcnn)*bcnn;
    return ans;
}

void Solve() {
    int l = CalLength(x,dx,t,dt),w = CalLength(d,dd,v,dv);
    cout << l*w << endl;
    cout << l/dx << " " << w/dd << " " << l/dt << " " << w/dv;
}

int main()
{
    freopen("XDTV1.INP", "r", stdin);
    freopen("XDTV1.OUT", "w", stdout);
    cin >> x >> dx >> d >> dd >> t >> dt >> v >> dv;
    Solve();
    return 0;
}
