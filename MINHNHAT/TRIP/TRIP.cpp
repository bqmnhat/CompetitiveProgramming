#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,d,m[100001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> m[i];
    }
}

void MinBoats() {
    while (cin >> n >> d) {
        ReadData();
        sort(m+1,m+1+n);
        int ans = 0, i = 1, j = n;
        while (i<j) {
            if (m[i] + m[j] <= d) {
                ans++;
                i++;
                j--;
            }
            else
                j--;
        }
        cout << n-ans << endl;
    }
}

int main()
{
    freopen("TRIP.INP", "r", stdin);
    freopen("TRIP.OUT", "w", stdout);
    MinBoats();
    return 0;
}
