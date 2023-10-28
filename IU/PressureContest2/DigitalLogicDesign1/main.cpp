#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxM 100
using namespace std;
int n, m, row[MaxN+1], col[MaxM+1], cnt1Row = 0, cnt1Col = 0, ans[MaxN+1][MaxM+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> row[i];
        cnt1Row += row[i];
    }
    for (int j=1; j<=m; j++) {
        cin >> col[j];
        cnt1Col += col[j];
    }
}

void Solve() {
    if ((cnt1Col + cnt1Row) & 1) {
        cout << "-1";
        return;
    }
    while (cnt1Col > cnt1Row) {
        int ColIter = 1, RowIter = 1;
        for (ColIter=1; ColIter<=m; ColIter++)
            if (col[ColIter] == 1)
                break;
        for (RowIter=1; RowIter<=n; RowIter++)
            if (row[RowIter] == 0)
                break;
        ans[RowIter][ColIter] = 1;
        col[ColIter] = 0;
        row[RowIter] = 1;
        cnt1Col--;
        cnt1Row++;
    }
    while (cnt1Row > cnt1Col) {
        int ColIter = 1, RowIter = 1;
        for (RowIter=1; RowIter<=n; RowIter++)
            if (row[RowIter] == 1)
                break;
        for (ColIter=1; ColIter<=m; ColIter++)
            if (col[ColIter] == 0)
                break;
        ans[RowIter][ColIter] = 1;
        col[ColIter] = 1;
        row[RowIter] = 0;
        cnt1Col++;
        cnt1Row--;
    }
    for (int i=1; i<=n; i++) {
        if (row[i] == 1) {
            for (int j=1; j<=m; j++) {
                if (col[j] == 1) {
                    ans[i][j] = 1;
                    col[j] = 0;
                    break;
                }
            }
            row[i] = 0;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++)
            cout << ans[i][j];
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    Solve();
    return 0;
}
