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
    while (cin >> n >> m) {
        ReadData();
        sort(a+1,a+1+n);
        int i=1, j = n,d = 0;
        while (i<j) {
            if (a[i]+a[j] <= m) {
                d++;
                i++;
                j--;
            }
            else {
                j--;
            }
        }
        cout << n-d << endl;
    }
}

int main()
{
    freopen("TRIP.INP","r", stdin);
    freopen("TRIP.OUT","w", stdout);
    Solve();
    return 0;
}
