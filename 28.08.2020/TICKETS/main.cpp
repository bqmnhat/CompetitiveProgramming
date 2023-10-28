#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

long long MinCost(ll n, ll k, ll p1, ll p2) {
    ll tap = (int)n/k, le = n%k;
    ll t1,t2,l1,l2;
    t1 = tap*p2;
    t2 = (tap*k)*p1;
    l1 = p2;
    l2 = le*p1;
    ll ans = min(t1,t2) + min(l1,l2);
    return ans;
}

int main()
{
    ll n,k,p1,p2;
    fi.open("TICKETS.INP");
    fo.open("TICKETS.OUT");
    fi >> n >> k >> p1 >> p2;
    fo << MinCost(n,k,p1,p2);
    return 0;
}
