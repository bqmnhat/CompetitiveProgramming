#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
typedef long long ll;
ll w,m,k;

void LengthOfX(ll x, int &l, ll &p) {
    p = 1;
    l = 0;
    while (x > 0) {
        x = x/10;
        p = p*10;
        l++;
    }
}

double LengthMax() {
    w = w/k;
    ll p;
    double ans = 0;
    int l;
    LengthOfX(m,l,p);
    while (w>0) {
        ll cost = (p-m)*l;
        if (w >= cost) {
            ans = ans + (p - m);
            m = p;
            p = p*10;
            l = l + 1;
            w = w - cost;
        }
        else
            break;
    }
    return ans + w/l;
}

int main()
{
    freopen("CONSEQ.INP", "r", stdin);
    freopen("CONSEQ.OUT", "w", stdout);
    cin >> w >> m >> k;
    cout << setprecision(0) << fixed << LengthMax();
    return 0;
}
