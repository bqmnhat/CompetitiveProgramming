#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2100000
#define MaxNSub2 300
using namespace std;
typedef long long ll;
int n, k, L, R, a[MaxN+1], MaxAi = 0;
ll dp[MaxNSub2+1][MaxNSub2+2][MaxNSub2+1], CntBitsSOS[MaxN+1], CntBits[MaxN+1], fac[MaxN+1], NumOfBits[MaxN+1], fSOS[MaxN+1]; // fSOS[S] = CntBitsSOS[S]
const ll Mod = 1e9 + 7;

//// Tools part
void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        MaxAi = max(MaxAi, a[i]);
    }
}

void CalculateFac() {
    fac[0] = 1;
    for (ll i=1; i<=MaxN; i++)
        fac[i] = (fac[i-1] * i)%Mod;
}

ll FastPow(ll val, ll base) {
    ll ans = 1;
    val%=Mod;
    while (base > 0) {
        if (base&1LL)
            ans = (ans * val)%Mod;
        val = (val * val)%Mod;
        base >>= 1LL;
    }
    return ans;
}

ll InvertMod(ll val) {
    return (FastPow(val, Mod - 2));
}

ll CHOOSE(ll k, ll n) {
    if ((n < 0) || (k < 0))
        return 0;
    if (n < k)
        return 0;
    ll ans = 0;
    ans = (fac[n]*(InvertMod(fac[n-k]*fac[k]))%Mod)%Mod;
    return ans;
}

void CountBits() {
    for (int i=1; i<=n; i++)
        CntBits[a[i]]++;
    for (int i=0; i<=MaxN; i++) {
        int bit = i, cnt = 0;
        while (bit > 0) {
            if (bit&1)
                cnt++;
            bit >>= 1;
        }
        NumOfBits[i] = cnt;
    }
}

int CntBitLen(ll val) {
    int ans = 0;
    while (val > 0) {
        ans++;
        val >>= 1LL;
    }
    return ans;
}

int CntBitOne(ll val) {
    int ans = 0;
    while (val > 0) {
        if (val&1)
            ans++;
        val >>= 1LL;
    }
    return ans;
}

/////// Solution part


ll SolutionFirstSub() {
    ll ans = 0;
    for (int i = 1; i < (1 << n); i++) {
        int bit = i, cnt = 0, cntOnes = 0;
        ll SumOr = 0;
        while (bit > 0) {
            cnt++;
            if (bit&1) {
                cntOnes++;
                SumOr |= a[cnt];
            }
            bit >>= 1;
        }
        if ((cntOnes == k) && (SumOr % 3 == 0) && (SumOr >= L) && (SumOr <= R)) {
            ans++;
            ans %= Mod;
        }
    }
    return ans;
}

ll SolutionSecondSub() {
    dp[0][0][0] = 1;
    if (L > MaxNSub2)
        return 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=k; j++) {
            for (int t=0; t<=MaxNSub2; t++) {
                dp[i+1][j][t] += dp[i][j][t];
                dp[i+1][j][t] %= Mod;
                if ((t | a[i+1]) <= MaxNSub2) {
                    dp[i+1][j+1][(t | a[i+1])] += dp[i][j][t];
                    dp[i+1][j+1][(t | a[i+1])] %= Mod;
                }
            }
        }
    }
    ll ans = 0;
    for (int i=L; i<=R; i++)
        if ((i%3 == 0) && (i <= MaxNSub2))
            ans = (ans + dp[n][k][i])%Mod;
    return ans;
}

ll SolutionSub3And4And5() {
    int len = 21;
    for (int i=0; i<(1<<len); i++)
        CntBitsSOS[i] = CntBits[i]; // CntBitsSOS[S] = number of ways to choose a[i]s such that a[i]s are submask of S => If we represent a[i] as bitset form: a[i] will sub in S (Meaning S have the on bits of a[i])
    // => dp SOS can even use for Counting problem related to OR operation
    for (int i=0; i < len; i++)
        for (int mask=0; mask < (1 << len); mask++)
            if (mask & (1LL << i))
                CntBitsSOS[mask] = (CntBitsSOS[mask] + CntBitsSOS[mask^(1LL << i)])%Mod;
    ll ans = 0;
    for (int i=0; i<(1<<len); i++) {
        // Inclusive-Exclusive theorem + Dp SOS
        if (NumOfBits[i]%2)
            fSOS[i] = CHOOSE(k, CntBitsSOS[i]);
        else
            fSOS[i] = (-1LL)*CHOOSE(k, CntBitsSOS[i]);
    }
    for (int i=0; i<len; i++) {
        for (int mask = 0; mask < (1 << len); mask++) {
            if (mask & (1 << i)) {
                if (NumOfBits[mask]%2)
                    fSOS[mask] = (fSOS[mask] + fSOS[mask^(1 << i)] + Mod)%Mod;
                else
                    fSOS[mask] = (-1LL)*(((-1LL)*(fSOS[mask] + fSOS[mask^(1 << i)] - Mod))%Mod);
            }
        }
    }
    for (int i=L; i<=R; i++) {
        if (i%3 != 0)
            continue;
        if (NumOfBits[i]%2)
            ans = (ans + fSOS[i])%Mod;
        else
            ans = (ans + ((-1LL)*fSOS[i]))%Mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    CalculateFac();
    cin >> n >> k >> L >> R;
    ReadData();
    CountBits();
    if ((n <= 20) && (MaxAi <= 200))
        cout << SolutionFirstSub();
    else if ((n <= 200) && (MaxAi <= 200))
        cout << SolutionSecondSub();
    else
        cout << SolutionSub3And4And5();
    return 0;
}
