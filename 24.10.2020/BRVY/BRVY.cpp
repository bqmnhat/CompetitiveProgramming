#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

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

ll CalSide(int a, int da, int b, int db) {
    ll lcm = (da*db)/GCD(da,db);
    ll tmp1 = da*a, tmp2 = db*b;
    return ll(min(tmp1,tmp2)/lcm)*lcm;
}

void Solve() {
    ll side1 = CalSide(x,dx,t,dt);
    ll side2 = CalSide(d,dd,v,dv);
    ll area = side1 * side2;
    if (area != 0) {
        cout << side1*side2 << endl;
        cout << side1/dx << " " << side2/dd << " " << side1/dt << " " << side2/dv;
    }
    else {
        cout << "0" << endl;
        cout << "0 0 0 0";
    }
}

int main()
{
    freopen("BRVY.INP", "r", stdin);
    freopen("BRVY.OUT", "w", stdout);
    cin >> x >> dx >> d >> dd >> t >> dt >> v >> dv;
    Solve();
    return 0;
}
