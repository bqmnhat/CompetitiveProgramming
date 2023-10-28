#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[10001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

long long Solution() {
    sort(a+1, a+1+n, greater<long long>());
    long long ans = max(a[1]*a[2]*a[3], a[1]*a[n]*a[n-1]);
    return ans;
}

int main()
{
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
