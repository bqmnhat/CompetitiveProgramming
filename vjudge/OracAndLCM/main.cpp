#include<iostream>
#include<bits/stdc++.h>
#define MaxN 100000
#define MaxVal 200000
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int n, a[MaxN+5], d[MaxVal+5], cntNotZero[MaxVal+5];
pii cnte[MaxVal+5];

void Init() {
    for (int i=1; i<=MaxVal; i++)
        cnte[i] = pii(-1, -1);
}

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakeSieve() {
    for (int i=2; i*i<=MaxVal; i++)
        if (d[i] == 0)
            for (int j=i; i*j<=MaxVal; j++)
                d[i*j] = i;
}

void Factorization(int val) {
    unordered_map<int, int> mu;
    mu.clear();
    while (val>1) {
        int p = d[val];
        if (p == 0)
            p = val;
        mu[p]++;
        val/=p;
    }
    for (auto it = mu.begin(); it != mu.end(); it++) {
        int p = (*it).first, cnt = (*it).second;
        cntNotZero[p]++;
        if ((cnte[p].first == -1) || (cnt <= cnte[p].first)) {
            cnte[p].second = cnte[p].first;
            cnte[p].first = cnt;
        }
        else if ((cnte[p].second == -1) || (cnt <= cnte[p].second))
            cnte[p].second = cnt;
    }
}

ll FastPow(ll base, ll e) {
    ll ans = 1;
    while (e) {
        if (e&1LL)
            ans = ans*base;
        base = base*base;
        e >>= 1LL;
    }
    return ans;
}

ll Solution() {
    for (int i=1; i<=n; i++)
        Factorization(a[i]);
    ll ans = 1;
    for (int i=2; i<=MaxVal; i++) {
        if (n - cntNotZero[i] >= 2)
            continue;
        if (n - cntNotZero[i] == 1)
            ans = ans*FastPow(i, cnte[i].first);
        else
            ans = ans * FastPow(i, cnte[i].second);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    Init();
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
