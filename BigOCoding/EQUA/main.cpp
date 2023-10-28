#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int K, primes[5001], lp = 0;
bool IsNotPrime[5001];
struct Ans {
    int x, y, z;
} ans[25000000];

void MakeSieve() {
    IsNotPrime[0] = IsNotPrime[1] = true;
    for (int i = 2; i*i <= K; i++)
        if (!IsNotPrime[i])
            for (int j = i; i*j <= K; j++)
                IsNotPrime[i*j] = true;
    for (int i=1; i<=K; i++) {
        if (!IsNotPrime[i]) {
            lp++;
            primes[lp] = i;
        }
    }
}

void Solve() {
    int cnt = 0;
    for (int xi = 1; xi<=lp && primes[xi] <= K; xi++) {
        for (int yi = xi; yi <= lp && primes[yi] <= K; yi++) {
            int z = K - primes[xi] - primes[yi];
            if ((z >= primes[yi]) && (z <= 5000) && (!IsNotPrime[z])) {
                cnt++;
                ans[cnt].x = primes[xi];
                ans[cnt].y = primes[yi];
                ans[cnt].z = z;
            }
        }
    }
    for (int i=1; i<=cnt; i++)
        cout << ans[i].x << ' ' << ans[i].y << ' ' << ans[i].z << '\n';
    cout << "0 0 0";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> K;
    MakeSieve();
    Solve();
    return 0;
}
