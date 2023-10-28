#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000000
using namespace std;
typedef long long ll;
int t, n;
bool Sieve[MaxN+1];
vector<int> p;

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i <= MaxN; i++)
        if (!Sieve[i])
            for (int j=i; i*j<=MaxN; j++)
                Sieve[i*j] = true;
    for (int i=2; i<=MaxN; i++)
        if (!Sieve[i])
            p.push_back(i);
}

int BinsearchLessThanEqualTo(int val) {
    int lo = 0, hi = p.size() - 1, ans = -1;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (p[mid] <= val) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans+1;
}

ll Solution() {
    ll ans = (1LL*n*(n-1LL)*(n-2))/6, tmp = 0;
    for (int i=1; i<=n; i++) {
        ll JPrimes = BinsearchLessThanEqualTo(i+n) - BinsearchLessThanEqualTo(i);
        if (i == 1)
            JPrimes--;
        ll JOthers = n - 1LL - JPrimes;
        tmp += (JPrimes*JOthers);
    }
    tmp >>= 1LL;
    ans -= tmp;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSieve();
    cin >> t;
    Solve();
    return 0;
}
