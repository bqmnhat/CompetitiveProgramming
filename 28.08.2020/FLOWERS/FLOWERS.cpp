// ax + by <= c
#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

long long MaxFlower(ll a, ll b, ll c) {
    ll x, y = 0, tmp = 0;
    ll k = c/b;
    while (y<=k) {
        x = (c-b*y)/a;
        if ((a*x + b*y <= c) and (a*x + b*y > tmp)) {
            tmp = a*x + b*y;
        }
        y++;
    }
    return tmp;
}

int main()
{
    ll a,b,c;
    fi.open("FLOWERS.INP");
    fo.open("FLOWERS.OUT");
    fi >> a >> b >> c;
    fo << MaxFlower(a,b,c);
    return 0;
}
