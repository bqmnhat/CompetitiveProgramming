#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m,n,k;

int Groups(int m, int n, int k) {
    int ans = min(m/2, n);
    int l = (m+n) - ans*3;
    while (l < k) {
        l = l + 3;
        ans--;
    }
    return ans;
}

int main()
{
    freopen("TH.INP", "r", stdin);
    freopen("TH.OUT", "w", stdout);
    cin >> m >> n >> k;
    cout << Groups(m,n,k);
    return 0;
}
