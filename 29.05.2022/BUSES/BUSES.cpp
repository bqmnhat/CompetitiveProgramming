#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n;
ll a[MaxN+1], k;
pll Ans1, Ans2;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] = a[i]%k;
        if (a[i] == 0)
            a[i] = k;
    }
}

void Solve() {
    Ans1 = Ans2 = pll(1e18, 1e9);
    for (int i=0; i<k; i++) {
        ll MaxTime = 0, SumTime = 0;
        for (int j=1; j<=n; j++) {
            ll WaitTime = i-a[j];
            if (WaitTime < 0)
                WaitTime += k;
            MaxTime = max(MaxTime, WaitTime);
            SumTime += WaitTime;
        }
        if (Ans1.first > SumTime)
            Ans1 = pll(SumTime, i);
        if (Ans2.first > MaxTime)
            Ans2 = pll(MaxTime, i);
    }
    cout << Ans1.first << ' ' << Ans1.second << '\n' << Ans2.first << ' ' << Ans2.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BUSES.INP", "r", stdin);
    freopen("BUSES.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    Solve();
    return 0;
}
