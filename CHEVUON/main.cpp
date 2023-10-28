#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1001][1001], m,n, tmp[1000001], l = 0, ans[1000001], d = 0;

void ReadData() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
}

void SortH() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            l++;
            tmp[l] = a[i][j];
        }
    }
    sort(tmp+1, tmp+1+l, greater<int>());
    int i = 1, j = 1, k = 1;
    while (j<=n) {
        while (i<=m) {
            for (int y=j; y<=min(j+1, n); y++) {
                for (int x=i; x<=min(i+1, m); x++) {
                    a[x][y] = tmp[k];
                    k++;
                }
            }
            i+=2;
        }
        i = 1;
        j+=2;
    }
}

void Solve() {
    SortH();
    int PMax = 0, TamLop, Ph = 0, i = 1,j = 1;
    while(j<=n) {
        while (i<=m) {
            if ((i==1) && (j==n)) {
                d++;
                ans[d] = a[i][j-1]+1;
                if (ans[d] == ans[d-1])
                    ans[d]++;
            }
            else if ((i==m) && (j==1)) {
                d++;
                ans[d] = a[i-1][j]+1;
                if (ans[d] == ans[d-1])
                    ans[d]++;
            }
            else if ((j==n) or (i==m)) {
                d++;
                ans[d] = a[i-1][j-1];
                if (ans[d] == ans[d-1])
                    ans[d]++;
            }
            else {
                d++;
                ans[d] = a[i][j]+1;
            }
            i+=2;
        }
        i=1;
        j+=2;
    }
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << d << endl;
    for (int i=1; i<=d; i++) {
        cout << ans[i] << " ";
    }
}

int main()
{
    freopen("CHEVUON.INP", "r", stdin);
    freopen("CHEVUON.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    Solve();
    return 0;
}
