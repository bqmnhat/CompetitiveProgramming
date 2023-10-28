#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m, a[60001];

long long Solution() {
    long long ans = 0;
    for (int i=m+1; i<=n; i++) {
        int x = i;
        int m = sqrt(x), j = 2;
        while ((j<=m) && (x>1)) {
            while (x%j == 0) {
                a[j]++;
                x = x/j;
            }
            j++;
        }
        if (x>1) {
            a[x]++;
        }
    }
    for (int i=2; i<=n-m; i++) {
        int x = i;
        int m = sqrt(x), j = 2;
        while ((j<=m) && (x>1)) {
            while (x%j == 0) {
                a[j]--;
                x = x/j;
            }
            j++;
        }
        if (x>1) {
            a[x]--;
        }
    }
    for (int i=1; i<=n; i++) {
        if (a[i] > 0)
            ans++;
    }
    return ans;
}

int main()
{
    freopen("CPRDIV.INP", "r", stdin);
    freopen("CPRDIV.OUT", "w", stdout);
    cin >> n >> m;
    cout << Solution();
    return 0;
}

