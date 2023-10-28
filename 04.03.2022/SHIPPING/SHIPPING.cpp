#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[1000002];
ll Left[1000002], Right[1000002], SumLeft[1000001], SumRight[1000001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void MakeLeftRight() {
    for (int i=1; i<=n; i++)
        Left[i] = Left[i-1] + 1LL*a[i];
    for (int i=n; i>=1; i--)
        Right[i] = Right[i+1] + 1LL*a[i];
}

ll Solution() {
    ll ans = 1e18;
    for (int i=1; i<n; i++)
        SumLeft[i+1] = SumLeft[i] + Left[i];
    for (int i=n; i>1; i--)
        SumRight[i-1] = SumRight[i] + Right[i];
    for (int i=0; i<=n; i++)
        ans = min(ans, SumLeft[i] + SumRight[i+1]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SHIPPING.INP", "r", stdin);
    freopen("SHIPPING.OUT", "w", stdout);
    cin >> n;
    ReadData();
    MakeLeftRight();
    cout << Solution();
    return 0;
}
