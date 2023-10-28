#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

ll LineIntersec(ll a, ll A, ll b, ll B) {
    if ((a>B) or (b>A)) {
        return 0;
    }
    else
        return abs(max(a,b) - min(A,B));
}

ll RecIntersec(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    ll a,b;
    if (x1>x2)
        swap(x1,x2);
    if (x3>x4)
        swap(x3,x4);
    if (y1>y2)
        swap(y1,y2);
    if (y3>y4)
        swap(y3,y4);
    a = LineIntersec(x1,x2,x3,x4);
    b = LineIntersec(y1,y2,y3,y4);
    return a * b;
}

int main()
{
    ll n,x1,y1,x2,y2,x3,y3,x4,y4;
    fi.open("INTERSEC.INP");
    fo.open("INTERSEC.OUT");
    fi >> n;
    for (ll i = 1; i <= n; i++) {
        fi >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        fo << RecIntersec(x1,y1,x2,y2,x3,y3,x4,y4) << endl;
    }
    return 0;
}
