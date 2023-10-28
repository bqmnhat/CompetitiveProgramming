#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n;

long long Solution() {
    int m = sqrt(n), i = 2;
    long long ans = 0;
    while ((i<=m) && (n>1)) {
        if (n%i==0) {
            ans++;
        }
        while (n%i == 0) {
            n=n/i;
        }
        i++;
    }
    if (n>1)
        ans++;
    return ans;
}

int main()
{
    freopen("COUNTPRD.INP", "r", stdin);
    freopen("COUNTPRD.OUT", "w", stdout);
    cin >> n;
    cout << Solution();
    return 0;
}
