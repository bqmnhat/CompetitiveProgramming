#include <iostream>
#include <bits/stdc++.h>
#define MaxN 5000000
using namespace std;
typedef long long ll;
int n;
ll p, q, m, k, a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        a[i] = (p*i + q)%m;
}

ll Solution() {
    ll res = 0;
    ll MinVal = 1e10, MaxVal = -1e10;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            MinVal = min(MinVal, a[j]);
            MaxVal = max(MaxVal, a[j]);
            if (MaxVal - MinVal <= k) res++;
        }
        MinVal = 1e10;
        MaxVal = -1e10;
    }
}

int main()
{
    freopen("SDIFF.INP", "r", stdin);
    freopen("SDIFF.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> p >> q >> m;
    cin >> k;
    ReadData();
    cout << Solution();
    return 0;
}
