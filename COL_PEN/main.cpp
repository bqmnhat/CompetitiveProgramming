#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[5];

int Solution() {
    int ans = 0;
    for (int i=1; i<=4; i++) {
        cin >> a[i];
    }
    sort(a+1,a+1+4);
    for (int i=2; i<=4; i++) {
        if (a[i] == a[i-1])
            ans++;
    }
    return ans;
}

int main()
{
    freopen("COL_PEN.INP", "r", stdin);
    freopen("COL_PEN.OUT", "w", stdout);
    cout << Solution();
    return 0;
}
