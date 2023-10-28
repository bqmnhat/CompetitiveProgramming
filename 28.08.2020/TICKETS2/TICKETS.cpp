#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

long long MinCost(ll n, ll k , ll p1, ll p2) {
    ll ans = n*p1;
    ll t = 0;
    ll s = n/k + 1;
    for (ll a = 0; a <= s; a++) {
        t = n - a*k;
        if ((a*p2 + t*p1) < ans) {
            ans = a*p2 + t*p1;
        }
    }
    return ans;
}

int main()
{
    ll n,k,p1,p2;
    fi.open("TICKETS.INP");
    fo.open("TICKETS.OUT");
    fi >> n >> k >> p1 >> p2;
    fo <<MinCost(n,k,p1,p2);
    return 0;
}
