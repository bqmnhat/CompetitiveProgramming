#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,a[100001];

void ReadData() {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}



void Solve() {
    int mid;
    while (cin >> n >> m) {
        ReadData();
        sort(a+1,a+1+n);

    }
}

int main()
{
    freopen("TRIP.INP","r", stdin);
    freopen("TRIP.OUT","w", stdout);
    Solve();
    return 0;
}
