#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

ll CalHive(ll n) {
    if (n == 1) {
        return 1;
    }
    else
        return 1 + 6*(n*(n-1))/2;
}

int main()
{
    ll n;
    fi.open("BEEHIVE.INP");
    fo.open("BEEHIVE.OUT");
    fi >> n;
    fo << CalHive(n);
    return 0;
}
