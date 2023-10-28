#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[200001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

ll Solution() {
    sort(a+1, a+1+n);
    ll sum = 0;
    for (ll i=1; i<=n; i++) {
        sum = sum + (a[i] * (i-1)) - (a[i] * (n-i));
    }
    return sum;
}

int main()
{
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
