#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int l[46], a[46], n, k,t;

void GenLA() {
    l[0] = 1;
    l[1] = 1;
    a[0] = 1;
    a[1] = 0;
    for (int i=2; i<=45; i++) {
        a[i] = a[i-2] + a[i-1];
        l[i] = l[i-2] + l[i-1];
    }
}

int MaxNofA(int n, int k) {
    int ans = 0;
    while (n>2) {
        if (k > l[n-2]) {
            ans += a[n-2];
            k = k - l[n-2];
            n--;
        }
        else
            n = n - 2;
    }
    if (n != 1)
        ans += 1;
    return ans;
}

void Solve() {
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        cout << MaxNofA(n,k) << endl;
    }
}

int main()
{
    freopen("FIB2.INP", "r", stdin);
    freopen("FIB2.OUT", "w", stdout);
    GenLA();
    Solve();
    return 0;
}
