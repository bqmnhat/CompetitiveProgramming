#include <iostream>
#include <bits/stdc++.h>
#define MaxN 3000000
using namespace std;
int t, a, b, cnt[MaxN+1];
bool Sieve[MaxN+1];

int SumDig(int x) {
    int ans = 0;
    while (x > 0) {
        ans += (x%10);
        x /= 10;
    }
    return ans;
}

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i <= MaxN; i++)
        if (!Sieve[i])
            for (int j=i; i*j <= MaxN; j++)
                Sieve[i*j] = true;
}

void CalCnt() {
    for (int i=1; i<=MaxN; i++) {
        cnt[i] = cnt[i-1];
        int Digits = SumDig(i);
        if ((!Sieve[i]) && (Digits%5 == 0))
            cnt[i]++;
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> a >> b;
        int ans = cnt[b] - cnt[a-1];
        cout << ans << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    cin >> t;
    MakeSieve();
    CalCnt();
    Solve();
    return 0;
}
