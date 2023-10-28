#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[200001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

int Solution() {
    int ans = 1;
    sort(a+1, a+1+n);
    for (int i=2; i<=n; i++) {
        if (a[i] != a[i-1])
            ans++;
    }
    return ans;
}

int main()
{
    freopen("DIFFERENCES.INP", "r", stdin);
    freopen("DIFFERENCES.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
