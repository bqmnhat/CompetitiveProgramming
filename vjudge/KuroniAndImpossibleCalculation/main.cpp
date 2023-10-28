#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define MaxM 1000
using namespace std;
typedef long long ll;
int n, m;
ll a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    if (n > m)
        return 0;
    ll ans = 1;
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
            ans = (ans * abs(a[i] - a[j]))%m;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
