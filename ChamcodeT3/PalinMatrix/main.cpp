#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[1001][1001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
}

bool IsPalin() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++)
            if (a[i][j] != a[j][i])
                return false;
    }
    return true;
}

int main()
{
    cin >> n;
    ReadData();
    if (!IsPalin())
        cout << "FALSE";
    else
        cout << "TRUE";
    return 0;
}
