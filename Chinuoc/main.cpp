#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long t,n;
bool a[1000001];

void Sieve() {
    int m = sqrt(1000000);
    a[0] = a[1] = true;
    for (int i=2; i<=m; i++) {
        if (a[i] == false) {
            for (int j=i; i*j<=1000000; j++) {
                a[i*j] = true;
            }
        }
    }
}


long long CntPow8() {
    long long i=2, ans = 0;
    while ((i*i*i*i*i*i*i*i) <= n)  {
        if (a[i] == false)
            ans++;
        i++;
    }
    return ans;
}

long long Cnt2Sqr() {
    long long ans = 0, m = sqrt(sqrt(n));
    for (int i=2; i<=m; i++) {
        if (a[i] == false) {
            int b = sqrt(n/(i*i));
            for (int j = i+1; j<=b; j++) {
                if (a[j] == false)
                    ans++;
            }
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << Cnt2Sqr() + CntPow8() << endl;
    }
}

int main()
{
    freopen("Chinuoc.INP", "r", stdin);
    freopen("Chinuoc.OUT", "w", stdout);
    cin >> t;
    Sieve();
    Solve();
    return 0;
}
