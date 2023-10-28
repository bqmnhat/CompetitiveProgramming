#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x[401][401], a[401][401], b[401][401], n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> x[i][j];
        }
    }
}

void CheoChinh() { // Cong don cac duong cheo song song voi duong cheo chinh
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            a[i][j] = x[i][j] + a[i-1][j-1];
        }
    }
}

void CheoPhu() { // Cong don cac duong cheo song song voi duong cheo phu
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            b[i][j] = x[i][j] + b[i-1][j+1];
        }
    }
}

int MaxBeauty() {
    int ans = -2e3;
    for (int i=2; i<=n; i++){
        for (int j = 1; j<=n-1; j++) {
            for (int t = 1; t<min(i, n-j+1); t++) {
                int val = (a[i][j+t] - a[i-t-1][j-1]) - (b[i][j] - b[i-t-1][j+t+1]);
                if (val > ans)
                    ans = val;
            }
        }
    }
    return ans;
}

int main()
{
    freopen("MATRIX.INP", "r", stdin);
    freopen("MATRIX.OUT", "w", stdout);
    cin >> n;
    ReadData();
    CheoChinh();
    CheoPhu();
    cout << MaxBeauty();
    return 0;
}
