#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[4][4];
int t;

void ReadData() {
    for (int i=1; i<=3; i++) {
        for (int j=1; j<=3; j++) {
            if ((i == 2) && (j == 2)) {
                a[i][j] = -1e9;
                continue;
            }
            cin >> a[i][j];
        }
    }
}

int CheckSolution() {
    int ans = 0;
    for (int i=1; i<=3; i++) {
        if (a[i][2] - a[i][1] == a[i][3] - a[i][2])
            ans++;
    }
    for (int i=1; i<=3; i++) {
        if (a[2][i] - a[1][i] == a[3][i] - a[2][i])
            ans++;
    }
    if (a[2][2] - a[1][1] == a[3][3] - a[2][2])
        ans++;
    if (a[2][2] - a[1][3] == a[3][1] - a[2][2])
        ans++;
    return ans;
}

int Solution() {
    int ans = 0, tmp, i = 1, j = 3;
    while (i <= 3) {
        a[2][2] = (a[1][i] + a[3][j])/2;
        ans = max(ans, CheckSolution());
        i++;
        j--;
    }
    a[2][2] = (a[2][1] + a[2][3])/2;
    ans = max(ans, CheckSolution());
    return ans;
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        ReadData();
        cout << "Case #" << i << ": " << Solution() << '\n';
    }
    return 0;
}
