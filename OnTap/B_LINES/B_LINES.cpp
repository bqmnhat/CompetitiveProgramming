#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m, n, k, tk[100001];

void ReadData() {
    int x;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++)
        {
            cin >> x;
            tk[x]++;
        }
    }
}

int Solution() {
    int sum = 0;
    sort(tk+1, tk+1+100000, greater<int>());
    for (int i=1; i<=k; i++) {
        sum = sum + tk[i];
    }
    return sum;
}

int main()
{
    freopen("B_LINES.INP", "r", stdin);
    freopen("B_LINES.OUT", "w", stdout);
    cin >> m >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
