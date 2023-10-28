#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n;

int MinMul(long long n) {
    int ans = 0;
    if (n == 1)
        return 0;
    if (n%2 == 0) {
        ans += 1 + MinMul(n/2);
    }
    else {
        ans += 2 + MinMul((n-1)/2);
    }
    return ans;
}

int main()
{
    freopen("POWER.INP", "r", stdin);
    freopen("POWER.OUT", "w", stdout);
    cin >> n;
    cout << MinMul(n);
    return 0;
}
