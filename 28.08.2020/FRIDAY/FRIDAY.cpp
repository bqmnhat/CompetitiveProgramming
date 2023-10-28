#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

int Dof613(ll n, int k) {
    ll t = (k+12)%7; // thu cua 13.01 nam n
    ll x = 1;
    while (t != 5) {
        t = (t+2)%7;
        x = x + 1;
    }
    ll ans;
    if (x>n)
        ans = 0;
    else
        ans = (int)(n-x)/7 + 1;
    return ans;
}

int main()
{
    ll n;
    int k;
    fi.open("FRIDAY.INP");
    fo.open("FRIDAY.OUT");
    fi >> n >> k;
    fo << Dof613(n,k);
    return 0;
}
