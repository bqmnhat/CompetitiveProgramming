#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;
ll x[100000];
ll y[100000];

void ReadXY(ll a[], ll b[], ll n) {
    for (ll i = 1; i <= n; i++) {
        fi >> a[i] >> b[i];
    }
}

ll CntR(ll a[], ll b[], ll n) {
    ll ans = 0;
    for (ll i = 3; i<=n; i++) {
        if ((x[i-1] > x[i-2]) && (y[i] < y[i-1])) {
            ans = ans + 1;
        }
        if ((y[i-1] > y[i-2]) && (x[i] > x[i-1])) {
            ans = ans + 1;
        }
        if ((y[i-1] < y[i-2]) && (x[i] < x[i-1])) {
            ans = ans + 1;
        }
        if ((x[i-1] < x[i-2]) && (y[i] > y[i-1])) {
            ans = ans + 1;
        }
    }
    return ans;
}

int main()
{
    ll n;
    fi.open("ROBOT.INP");
    fo.open("ROBOT.OUT");
    fi >> n;
    ReadXY(x,y,n);
    fo << CntR(x,y,n);
    return 0;
}
