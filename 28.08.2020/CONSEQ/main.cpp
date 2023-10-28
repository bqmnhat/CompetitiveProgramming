#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
typedef long long ll;
ll w,m,k;

void LengthOf(ll x, ll &p, int &d) {
    d = 0;
    p = 1;
    while (x > 0) {
        x = x/10;
        d = d + 1;
        p = p*10;
    }
}

double MaxLength(ll w, ll m, ll k) {
    int d;
    double ans = 0;
    w = w/k;
    ll p;
    LengthOf(m,p,d);
    while (w > 0) {
        ll cost = (p-m)*d;
        if (w >= cost) {
            ans = ans + (p-m);
            ++d;
            m = p;
            p = p*10;
            w = w - cost;
        }
        else break;
    }
    return ans + w/d;
}

int main()
{
    freopen("CONSEQ.INP", "r", stdin);
    freopen("CONSEQ.OUT", "w", stdout);
    cin >> w >> m >> k;
    cout << setprecision(0) << fixed << MaxLength(w,m,k);
    return 0;
}
