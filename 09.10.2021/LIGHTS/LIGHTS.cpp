#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> Ipair;
int n, m, la = 0, lb = 0;
ll Connected[36];
Ipair a[1000001], b[1000001];

void InitData() {
    int u,v;
    for (int i=1; i<=m; i++) {
        cin >> u >> v;
        Connected[u-1] = (Connected[u-1]^(1LL<<(v-1)));
        Connected[v-1] = (Connected[v-1]^(1LL<<(u-1)));
    }
    for (int i=0; i<n; i++)
        Connected[i] = (Connected[i]^(1LL<<i));
}

ll NextBit(int num, int Disp) {
    ll ans = 0;
    int cnt = 0;
    while (num > 0) {
        ll tmp = (num&1);
        if (tmp == 1)
            ans = (ans^Connected[cnt+Disp]);
        num = (num >> 1);
        cnt++;
    }
    return ans;
}

int BinSearch(ll val, int lo, int hi) {
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (b[m].first == val)
            return m;
        else if (b[m].first < val)
            lo = m + 1;
        else
            hi = m - 1;
    }
    return -1;
}

void MakeAB() {
    a[0].first = -1;
    b[0].first = -1;
    int x = n/2;
    int tmp = (1<<x);
    for (int i=0; i < tmp; i++) {
        la++;
        a[la].first = NextBit(i, 0);
        a[la].second = i;
    }
    x = n - (n/2);
    tmp = (1<<x);
    for (int i=0; i<tmp; i++) {
        lb++;
        b[lb].first = NextBit(i, n/2);
        b[lb].second = i;
    }
}

int CalSwitches(int num) {
    int ans = 0;
    while (num > 0) {
        int tmp = (num&1);
        if (tmp == 1)
            ans++;
        num = (num >> 1);
    }
    return ans;
}

void Compress(Ipair x[1000001], int &lx) {
    int l = 0;
    for (int i=1; i<=lx; i++) {
        if (x[i].first != x[i-1].first) {
            l++;
            x[l].first = x[i].first;
            x[l].second = x[i].second;
        }
        else
            x[l].second = min(x[l].second, x[i].second);
    }
    lx = l;
}

int Solution() {
    int ans = 1e9;
    ll SumXor = (1LL<<n)-1LL;
    sort(a+1, a+la+1);
    sort(b+1, b+lb+1);
    Compress(a,la);
    Compress(b,lb);
    for (int i=1; i<=la; i++) {
        int tmp = BinSearch((SumXor^a[i].first), 1, lb);
        int switches = CalSwitches(b[tmp].second) + CalSwitches(a[i].second);
        if ((tmp != -1) && (switches < ans))
            ans = switches;
    }
    return ans;
}
int main()
{
    freopen("LIGHTS.INP", "r", stdin);
    freopen("LIGHTS.OUT", "w", stdout);
    cin >> n >> m;
    InitData();
    MakeAB();
    cout << Solution();
    return 0;
}

