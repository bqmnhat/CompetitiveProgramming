#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
ll a[MaxN+1];
int n;

ll Solution() {
    a[0] = a[1] = 1;
    for (int i=1; 2*i+1 <= n; i++) {
        a[2*i] = a[i] + a[i-1];
        a[2*i+1] = a[i] - a[i-1];
    }
    return a[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << Solution();
    return 0;
}
