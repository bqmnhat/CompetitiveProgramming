#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, maxVal = 0;
bool dda[1000001], ddb[1000001];

void ReadData() {
    int val;
    for (int i=1; i<=n; i++) {
        cin >> val;
        dda[val] = true;
        if (val > maxVal)
            maxVal = val;
    }
    for (int i=1; i<=n; i++) {
        cin >> val;
        ddb[val] = true;
        if (val > maxVal)
            maxVal = val;
    }
}

int MaxMul(bool x[], int d) {
    int u = (maxVal/d)*d;
    while ((x[u] == false) && (u > 0)) {
        u = u - d;
    }
    return u;
}

int Solution() {
    for (int d = maxVal; d>=1; d--) {
        int ai = MaxMul(dda, d);
        int bj = MaxMul(ddb, d);
        if ((ai > 0) && (bj > 0)) {
            return (ai + bj);
        }
    }
    return 0;
}

int main()
{
    freopen("MAXGCD.INP", "r", stdin);
    freopen("MAXGCD.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
