#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x[1000001], y[1000001], n;

void ReadData() {
    int valx, valy;
    for (int i = 1; i<=n; i++) {
        cin >> valx >> valy;
        x[valx]++;
        y[valy]++;
    }
}

int CountTri() {
    int ans = 0;
    for (int i = 0; i<=1000; i++) {
        for (int j = 0; j<=1000; j++) {
            if ((x[i] != 0) && (y[j] != 0))
                ans = ans + (x[i]-1)*(y[j]-1);
        }
    }
    return ans;
}

int main()
{
    freopen("TRICOUNT.INP", "r", stdin);
    freopen("TRICOUNT.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << CountTri();
    return 0;
}
