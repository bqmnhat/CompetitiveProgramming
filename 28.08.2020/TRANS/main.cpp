#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;
ll n,a,b,x,y;

void TransBuss(ll n, ll a, ll b, ll &x, ll &y) {
    ll tmpx,tmpy,tmps = -1; // tmpx : bus; tmpy : taxi ; x: final ans for bus; y: final ans for taxi
    tmpy = 0;
    ll r;
    while (tmpy <= n/4) {
        tmpx = (n-4*tmpy)/50;
        r = n - (50*tmpx + 4*tmpy);
        if (r > 0){
            if ((ceil(double(r)/4) * b) <= a)
                tmpy = tmpy + ceil(double(r)/4);
            else
                tmpx = tmpx + 1;
        }
        if (((tmpx*a + tmpy*b) < tmps) || (tmps == -1)) {
            tmps = tmpx*a + tmpy*b;
            x = tmpx;
            y = tmpy;
        }
        tmpy = tmpy + 1;
    }
}

int main()
{
    fi.open("TRANS.INP");
    fo.open("TRANS.OUT");
    fi >> n >> a >> b;
    TransBuss(n,a,b,x,y);
    fo << x << " " << y;
    return 0;
}
