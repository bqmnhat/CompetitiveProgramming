#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a,b;
long long Sieve[10000001];

void MakeSieve() {
    int t = sqrt(10000000);
    for (int i=1; i<=t; i++) {
        Sieve[i*i] = Sieve[i*i] + i;
        for (int j=i+1; j<=10000000/i; j++) {
            Sieve[i*j] = Sieve[i*j] + i + j;
        }
    }
}

long long Solution() {
    long long ans = 0;
    for (int i=a; i<=b; i++) {
        ans = ans + abs(i - (Sieve[i] - i));
    }
    return ans;
}

int main()
{
    MakeSieve();
    freopen("IMPERFECT.INP", "r", stdin);
    freopen("IMPERFECT.OUT", "w", stdout);
    cin >> a >> b;
    cout << Solution();
    return 0;
}
