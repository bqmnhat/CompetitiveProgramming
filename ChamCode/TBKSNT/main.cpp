#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
bool Sieve[5000001];

void MakeSieve() {
    int m = sqrt(n);
    Sieve[1] = Sieve[0] = true;
    for (int i=2; i<=m; i++) {
        if (!Sieve[i]) {
            for (int j=i; i*j<=n; j++)
                Sieve[i*j] = true;
        }
    }
}

double Solution() {
    double ans = 0;
    int cnt = 0;
    for (long long i=2; i<=n; i++) {
        if (!Sieve[i]) {
            ans = ans + i;
            cnt++;
        }
    }
    ans = ans/double(cnt);
    return ans;
}

int main()
{
    cin >> n;
    MakeSieve();
    cout << setprecision(3) << fixed << Solution();
    return 0;
}
