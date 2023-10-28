#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

ll GCD(ll x, ll y) {
    ll tmp;
    while (y != 0) {
        tmp = y;
        y = x % y;
        x = tmp;
    }
    return x;
}

ll CalSide(ll a, ll da, ll b, ll db) {
    ll LCM = (da * db)/GCD(da, db);
    ll tmp1 = a*da, tmp2 = b*db;
    ll ans = ll(min(tmp1,tmp2)/LCM) * LCM;
    return ans;
}

void Rectangle(ll x, ll dx, ll d, ll dd, ll t, ll dt, ll v, ll dv) {
    ll side1 = CalSide(x,dx,t,dt), side2 = CalSide(d,dd,v,dv);
    ll area = side1 * side2;
    if (area > 0) {
        fo << side1 * side2 << endl;
        fo << side1/dx << " " << side2/dd << " " << side1/dt << " " << side2/dv;
    }
    else {
        fo << 0 << endl;
        fo << "0 0 0 0";
    }
}

int main()
{
    ll x,dx,d,dd,t,dt,v,dv;
    fi.open("BRVY.INP");
    fo.open("BRVY.OUT");
    fi >> x >> dx >> d >> dd >> t >> dt >> v >> dv;
    Rectangle(x,dx,d,dd,t,dt,v,dv);
    return 0;
}
