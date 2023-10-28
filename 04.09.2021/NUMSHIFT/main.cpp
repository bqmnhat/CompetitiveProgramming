#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n;

long long Solution() {
    long long ans = n, kshf = 0;
    while ((1 << kshf) <= n) {
        kshf++;
    }
    kshf--;
    for (int i=1; i<=kshf; i++) {
        long long lastdig = n&1;
        long long newadd = lastdig << kshf;
        n = n >> 1;
        n = n^newadd;
        if (n > ans)
            ans = n;
    }
    return ans;
}

int main()
{
    freopen("NUMSHIFT.INP", "r", stdin);
    freopen("NUMSHIFT.OUT", "w", stdout);
    cin >> n;
    cout << Solution();
    return 0;
}
