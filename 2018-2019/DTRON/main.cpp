#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;

int Solution() {
    int val, ans = 0;
    for (int i=1; i<=n; i++) {
        cin >> val;
        if (val > k) {
            ans++;
        }
    }
    return ans;
}

int main()
{
    freopen("DTRON.INP", "r", stdin);
    freopen("DTRON.OUT", "w", stdout);
    cin >> n >> k;
    cout << Solution();
    return 0;
}
