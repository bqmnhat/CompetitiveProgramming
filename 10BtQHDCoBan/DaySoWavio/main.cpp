#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, Left[1000001], Right[1000001], a[1000001];

void ReadData() {
    for (int i = 1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++)
        Left[i] = Right[i] = 1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<i; j++)
            if (a[j] < a[i])
            Left[i] = max(Left[i], Left[j] + 1);
    for (int i=n; i>=1; i--)
        for (int j=n; j>i; j--)
            if (a[j] < a[i])
                Right[i] = max(Right[i], Right[j] + 1);
    for (int i=1; i<=n; i++)
        ans = max(ans, Left[i] + Right[i] - 1);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("14.INP", "r", stdin);
    freopen("14.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
