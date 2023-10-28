#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m, P[1000001];

void ReadData() {
    for (int i = 1; i<=m; i++) {
        cin >> P[i];
    }
}

void Solve() {
    int price, sum = 0;
    sort(P+1,P+1+m);
    for (int i=1; i<=m; i++) {
        int tmp = min(n, m-i+1);
        if (tmp*P[i] > sum) {
            price = P[i];
            sum = tmp*P[i];
        }
    }
    cout << price << " " << sum;
}

int main()
{
    freopen("AUCTION.INP", "r", stdin);
    freopen("AUCTION.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}

