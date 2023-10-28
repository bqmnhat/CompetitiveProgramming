#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;

int FindDay(int w, ll d, ll m) {
    ll a = ((m-1)*30)%7;
    ll b = m/2;
    b = b%7;
    ll c = (d-1)%7;
    ll k = (a+b+c)%7;
    if ((w+k)%7 == 0)
        return 7;
    else
        return (w + k)%7;
}

int main()
{
    int w;
    ll d,m;
    fi.open("CALENDAR.INP");
    fo.open("CALENDAR.OUT");
    fi >> w >> d >> m;
    fo << FindDay(w,d,m);
    return 0;
}
