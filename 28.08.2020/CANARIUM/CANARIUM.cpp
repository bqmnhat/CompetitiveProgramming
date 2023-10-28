#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

void Canarium(ll k, ll &m, ll &n) {
    ll x = 1, y;
    ll c = (int)sqrt(k);
    ll a = -1, b = -1;
    while (x<c) {
        y = (2*k-x-1)/(2*x+1);
        if (x*y + (x+1)*(y+1) == 2*k) {
            if ((a == -1) && (b == -1)) {
                if (x <= y) {
                    a = x;
                    b = y;
                }
                else
                {
                    a = y;
                    b = x;
                }
            }
            else if (abs(y-x) < abs(b-a)) {
                if (x <= y) {
                    a = x;
                    b = y;
                }
                else
                {
                    a = y;
                    b = x;
                }
            }
        }
        x = x + 1;
    }
    m = a;
    n = b;
}

int main()
{
    ll k,m,n;
    fi.open("CANARIUM.INP");
    fo.open("CANARIUM.OUT");
    while (fi >> k)
    {
        Canarium(k,m,n);
        fo << m << " " << n << endl;
    }
    return 0;
}
