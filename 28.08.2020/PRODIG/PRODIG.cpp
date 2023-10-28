#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;

void Rev(ll &n) {
    ll ans = 0;
    while (n > 0) {
        ans = ans * 10 + (n%10);
        n = n/10;
    }
    n = ans;
}

ll FindM(ll n) {
    ll ans = 0;
    if (n == 0)
        return 10;
    if (n <= 9)
        return n;
    for (int i = 9; i >= 2; --i) {
        while (n%i == 0) {
            ans = ans*10 + i;
            n = n/i;
        }
    }
    Rev(ans);
    if (n > 9)
        return -1;
    else
        return ans;
}

int main()
{
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("PRODIG.INP");
    fo.open("PRODIG.OUT");
    fi >> n;
    fo << FindM(n);
    return 0;
}
