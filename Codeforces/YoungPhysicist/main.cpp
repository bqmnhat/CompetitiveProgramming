#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, x[101], y[101], z[101];

void ReadData() {
    for (int i=1; i<=n; i++) {
        int xi,yi,zi;
        cin >> xi >> yi >> zi;
        x[i] = x[i-1] + xi;
        y[i] = y[i-1] + yi;
        z[i] = z[i-1] + zi;
    }
}

bool IsEquilibrium() {
    if ((x[n] != 0) || (y[n] != 0) || (z[n] != 0))
        return false;
    return true;
}

int main()
{
    cin >> n;
    ReadData();
    if (IsEquilibrium())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
