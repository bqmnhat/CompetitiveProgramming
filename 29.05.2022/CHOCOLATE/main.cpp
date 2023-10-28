#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20
using namespace std;
int n, m, board[MaxN+1][MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            cin >> board[i][j];
}

bool CanCut() {
    for (int j=1; j<m; j++) {
        bool CanCutAtLine = true;
        for (int i=1; i<=n; i++) {
            if (board[i][j] == board[i][j+1]) {
                CanCutAtLine = false;
                break;
            }
        }
        if (CanCutAtLine)
            return true;
    }
    for (int i=1; i<n; i++) {
        bool CanCutAtLine = true;
        for (int j=1; j<=m; j++) {
            if (board[i][j] == board[i+1][j]) {
                CanCutAtLine = false;
                break;
            }
        }
        if (CanCutAtLine)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CHOCOLATE.INP", "r", stdin);
    freopen("CHOCOLATE.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    if (CanCut())
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
