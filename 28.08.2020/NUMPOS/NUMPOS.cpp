#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

ll PosOfK(ll k) {
    if (k>3)
        return 3*(k-2);
    else
        return k;
}

int main()
{
    ll k;
    fi.open("NUMPOS.INP");
    fo.open("NUMPOS.OUT");
    fi >> k;
    fo << PosOfK(k);
    return 0;
}
