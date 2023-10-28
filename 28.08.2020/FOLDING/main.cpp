#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;
ll W,H,w,h;

ll SideFold(ll a, ll b) { // folding side length a => b
    ll ans = 0;
    while (b < a) {
        ans = ans + 1;
        b = b * 2;
    }
    return ans;
}

ll FoldCounter(ll W, ll H, ll w, ll h) {
    ll ans = 0;
    if ((w > max(W,H)) or (h > max(W,H)))
        return -1;
    if (w*h > W*H)
        return -1;
    ll tmp1 = SideFold(W,w) + SideFold(H,h), tmp2 = SideFold(W,h) + SideFold(H,w);
    ans = min(tmp1,tmp2);
    return ans;
}

int main()
{
    fi.open("FOLDING.INP");
    fo.open("FOLDING.OUT");
    fi >> W >> H >> w >> h;
    fo << FoldCounter(W,H,w,h);
    return 0;
}
