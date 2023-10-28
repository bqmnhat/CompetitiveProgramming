#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;
ll n,a,b,x,y;

void TransBuss(ll n, ll a, ll b, ll &x, ll &y) {
    ll gr1 = n/50, gr2 = n%50;
    ll busc, taxic;
    x = 0;
    y = 0;
    busc = gr1*a;
    taxic =  ceil(double(gr1*50)/4) * b;
    if (busc < taxic)
        x = x + gr1;
    else
        y = y + ceil(double(gr1*50)/4);
    busc = a;
    taxic = ceil(double(gr2)/4) * b;
    if (busc < taxic)
        x = x + 1;
    else
        y = y + ceil(double(gr2)/4);
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
