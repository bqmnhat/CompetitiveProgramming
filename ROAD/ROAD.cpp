#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n,k,cd[1000001];

void ReadData() {
    long long a;
    for (int i=1; i<=n; i++) {
        cin >> a;
        cd[i] = cd[i-1]+a;
    }
}

void Solve() {
    int i=1, j=n;
    while (i<=j) {
        int tmp = cd[j] - cd[i-1];
        if (tmp > (j-i+1)*k)
            j--;
        else if (tmp < (j-i+1)*k)
            i++;
        else {
            cout << i << " " << j-i+1;
            return;
        }
    }
    cout << "0";
}

int main()
{
    freopen("ROAD.INP", "r", stdin);
    freopen("ROAD.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    Solve();
    return 0;
}
