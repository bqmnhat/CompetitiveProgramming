#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int m, di[27], dj[27];
string s;

ll ValOfBox(ll u, ll v) {
    ll Diag = (u+v)-1;
    bool FromBottomRight = false;
    if (Diag>n) {
        Diag = 2*n - Diag;
        FromBottomRight = true;
    }
    ll DiagStart;
    if (Diag%2 == 0) {
        DiagStart = 1LL*Diag*1LL*(Diag-1LL)/2 + 1LL;
        if (FromBottomRight) {
            DiagStart = n*n - DiagStart + 1LL;
            return (DiagStart - n + u);
        }
        else
            return (DiagStart + u - 1LL);
    }
    else {
        DiagStart = 1LL*Diag*1LL*(Diag+1LL)/2;
        if (FromBottomRight) {
            DiagStart = n*n - DiagStart + 1LL;
            return (DiagStart + n - u);
        }
        else
            return (DiagStart - u + 1LL);
    }
}

void Init() {
    di['U' - 'A'] = -1;
    dj['U' - 'A'] = 0;
    di['R' - 'A'] = 0;
    dj['R' - 'A'] = 1;
    di['D' - 'A'] = 1;
    dj['D' - 'A'] = 0;
    di['L' - 'A'] = 0;
    dj['L' - 'A'] = -1;
}

ll Solution() {
    int NowX = 1, NowY = 1;
    ll ans = 1;
    for (int i=0; i<m; i++) {
        NowX += di[s[i] - 'A'];
        NowY += dj[s[i] - 'A'];
        ans += ValOfBox(NowX, NowY);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("JUMP.INP", "r", stdin);
    freopen("JUMP.OUT", "w", stdout);
    cin >> n >> m >> s;
    Init();
    cout << Solution();
    return 0;
}
