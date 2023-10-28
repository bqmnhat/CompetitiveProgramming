#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
#define MaxVal 1000000
using namespace std;
typedef long long ll;
int t, n, Sieve[MaxVal+5], ans[MaxN+5];

void MakeSieve() {
    for (int i=2; i*i<=MaxVal; i++)
        if (Sieve[i] == 0)
            for (int j=i; i*j <= MaxVal; j++)
                Sieve[i*j] = i;
}

int CntPrimes(int val) {
    unordered_map<ll, int> mark;
    int cnt = 0;
    while (val > 1) {
        int p = Sieve[val];
        if (p == 0)
            p = val;
        if (mark.find(p) == mark.end()) {
            cnt++;
            mark[p]++;
        }
        val /= p;
    }
    return cnt;
}

void CntNumbers() {
    int cnt = 0, i = 1;
    while (cnt < MaxN) {
        int tmp = CntPrimes(i);
        if (tmp >= 3) {
            cnt++;
            ans[cnt] = i;
        }
        i++;
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << ans[n] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    MakeSieve();
    CntNumbers();
    Solve();
    return 0;
}
