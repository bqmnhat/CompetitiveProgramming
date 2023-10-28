#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, a, b, k, Prime[1000001], lp = 0;
bool Sieve[1000001];

void MakePrime() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i <= 1000000; i++)
        if (!Sieve[i])
            for (int j = i; i*j <= 1000000; j++)
                Sieve[i*j] = true;
    for (int i=2; i<=1000000; i++) {
        if (!Sieve[i]) {
            lp++;
            Prime[lp] = i;
        }
    }
}

int SumExpPrime(int x) {
    int ans = 0;
    for (int i=1; i<=lp; i++) {
        if (Prime[i]*Prime[i] > x)
            break;
        while (x % Prime[i] == 0) {
            x = x/Prime[i];
            ans++;
        }
    }
    if (x > 1)
        ans++;
    return ans;
}

void SolveTestCase() {
    int MinMove, g = __gcd(a,b);
    if (a == b)
        MinMove = 0;
    else if ((g == a) || (g == b))
        MinMove = 1;
    else
        MinMove = 2;
    int MaxMove = SumExpPrime(a) + SumExpPrime(b);
    if (((MinMove <= k) && (k <= MaxMove) && (k != 1)) || ((MinMove <= k) && (k <= MaxMove) && (k == 1) && (MinMove == 1)))
        cout << "YES";
    else
        cout << "NO";
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> a >> b >> k;
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakePrime();
    cin >> t;
    Solve();
    return 0;
}
