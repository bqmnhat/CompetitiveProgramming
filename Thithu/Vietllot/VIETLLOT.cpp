#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m, n, a[200001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

int Solution() {
    sort(a+1, a+1+n);
    long long sum = 0;
    int ans = 0, i = 1;
    while ((sum + a[i] <= m) && (i<=n)) {
        sum = sum + a[i];
        ans++;
        i++;
    }
    return ans;
}

int main()
{
    cin >> m >> n;
    ReadData();
    cout << Solution();
    return 0;
}
