#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[1001], Sum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        Sum += a[i];
    }
}

ll Solution() {
    ll MaxSum = 0;
    for (int i=1; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            ll tmp;
            if (j == i+1)
                tmp = Sum - a[i] - a[i+1] - a[j+1] + (a[i] * a[i+1] * a[j+1]);
            else
                tmp = Sum - a[i] - a[i+1] - a[j] - a[j+1] + (a[i]*a[i+1]) + (a[j]*a[j+1]);
            MaxSum = max(MaxSum, tmp);
        }
    }
    return MaxSum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("EXPRESS.INP", "r", stdin);
    freopen("EXPRESS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
