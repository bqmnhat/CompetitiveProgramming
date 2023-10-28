#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef unsigned __int128 i128;
const ll MaxLL = 10000000000000000000ULL;
int t;
ll n;
bool Sieve[3000001];
vector<ll> primes, AvailableNums;

// Case n is prime: Miller-Rabin

i128 FastPow(i128 x, i128 e, i128 Mod) {
    i128 ans = (x > i128(1));
    x %= Mod;
    while (e > 0) {
        if (e&i128(1))
            ans = (ans*x)%Mod;
        x = (x*x)%Mod;
        e >>= i128(1);
    }
    return ans;
}

bool MillerTest(i128 a, i128 d, i128 n) {
    i128 x = FastPow(a, d, n);
    if ((x == i128(1)) || (x == n-i128(1)))
        return false;
    while (d != n-i128(1)) {
        x = i128(x*x)%n;
        d *= i128(2);
        if (x == n-i128(1))
            return false;
    }
    return true;
}

bool IsPrime(i128 n) {
    if (n < 4)
        return ((n == 2) || (n == 3));
    i128 d = n - i128(1);
    while ((d & i128(1)) == 0)
        d >>= i128(1);
    for (auto a: {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}) {
        if (n == a)
            return true;
        if (MillerTest(a, d, n))
            return false;
    }
    return true;
}

// Case == 2 pis: Find the smaller one which is <= sqrt(n). Distance between 2 primes <= 300 => Fast to just find 1
// Case >= 3 pis: Generate a sieve which stores all numbers with such properties

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i <= 3000000; i++)
        if (!Sieve[i])
            for (int j=i; i*j<=3000000; j++)
                Sieve[i*j] = true;
    for (int i=2; i<=3000000; i++)
        if (!Sieve[i])
            primes.push_back(i);
}

void GenerateAvailableNums() {
    for (int i=0; i<primes.size(); i++) {
        ll Num = 1ULL;
        for (int j=i; j<primes.size(); j++) {
            if (Num > MaxLL/primes[j])
                break;
            Num *= primes[j];
            AvailableNums.push_back(Num);
        }
    }
    sort(AvailableNums.begin(), AvailableNums.end());
}

ll SafeSqrt(ll n) {
    ll tmp = sqrt(n) + 3;
    while (1ULL*tmp*tmp > n)
        tmp--;
    return tmp;
}

ll NxtPrimes(ll n) {
    if (n <= 2)
        return 2;
    if (n%2 == 0)
        ++n;
    while (!IsPrime(n))
        n += 2;
    return n;
}

bool CheckIsConsecutive(ll x) {
    if (x == 1ULL)
        return false;
    if (IsPrime(x))
        return true;
    if (binary_search(AvailableNums.begin(), AvailableNums.end(), x))
        return true;

    ll Nxt = NxtPrimes(SafeSqrt(x) + 1ULL);
    if (x%Nxt)
        return false;
    ll tmp = x/Nxt;
    if (!IsPrime(tmp))
        return false;
    return ((NxtPrimes(tmp+1ULL) == Nxt) && (Nxt*tmp == x));
}

void Solve() {
    MakeSieve();
    GenerateAvailableNums();
    for (int i=1; i<=t; i++) {
        cin >> n;
        if (CheckIsConsecutive(n))
            cout << "NICE";
        else
            cout << "UGLY";
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
