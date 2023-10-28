#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k, a[51];

int Solution() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1, a+1+n, greater<int>());
    int ans = 0, i = 1;
    while ((a[i] >= a[k]) && (i <= n)) {
        if (a[i] > 0)
            ans++;
        i++;
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    cout << Solution();
    return 0;
}
