#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100050
using namespace std;
typedef long long ll;
int n, a[MaxN+1];
ll f[MaxN+1], cnt[MaxN+1], Mob[MaxN+1], pcnt[MaxN+1]; //Mob and pcnt together is Mobius function
bool Sieve[MaxN+1];
const ll Mod = 1e9 + 7;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakeSieve() {
    for (int i=1; i<=MaxN; i++) {
        Mob[i] = 1;
        pcnt[i] = 0;
    }
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i<=MaxN; i++) {
        if (!Sieve[i]) {
            for (int j=1; i*j<=MaxN; j++) {
                if (i*j != i)
                    Sieve[i*j] = true;
                Mob[i*j] *= i;
                pcnt[i*j]++;
            }
        }
    }
}

ll FastPow(ll base, int e) {
    ll ans = 1;
    while (e > 0) {
        if (e&1)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1;
    }
    return ans;
}

bool IsSqr(int val) {
    int tmp = sqrt(val);
    return (tmp*tmp == val);
}

void CalCnt(int val) {
    int tmp = sqrt(val);
    for (int i=1; i<=tmp; i++) {
        if (val%i == 0) {
            cnt[i]++;
            cnt[val/i]++;
        }
    }
    if (IsSqr(val)) {
        int t = sqrt(val);
        cnt[t]--;
    }
}

void MakeF() {
    for (int i=1; i<=MaxN; i++)
        f[i] = (FastPow(2, cnt[i]) - 1LL + Mod*Mod)%Mod; // Total subsequences generated from a list consist of n numbers is 2^n
}

ll Solution() {
    for (int i=1; i<=n; i++)
        CalCnt(a[i]);
    MakeF();
    ll ans = 0;
    for (int i=1; i<=MaxN; i++) {
        if (i == 1)
            ans = (ans + f[i])%Mod;
        else if (Mob[i] == i) {
            if (pcnt[i]&1)
                ans = (ans - f[i] + Mod*Mod)%Mod;
            else
                ans = (ans + f[i])%Mod;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    MakeSieve();
    cout << Solution();
    return 0;
}
