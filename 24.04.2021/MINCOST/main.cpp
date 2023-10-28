#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000001], b[1000001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void MinCost() {
    int j = 0, i = 1;
    long long cost = 0;
    b[0] = 2e9;
    while (i <= n) {
        if (a[i] < b[j]) {
            j++;
            b[j] = a[i];
            i++;
        }
        else {
            cost = cost + min(a[i],b[j-1]);
            j--;
        }
    }
    for (int i=1; i<=j-1; i++) {
        cost += b[i];
    }
    cout << cost;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MINCOST.INP", "r", stdin);
    freopen("MINCOST.OUT", "w", stdout);
    cin >> n;
    ReadData();
    MinCost();
    return 0;
}
