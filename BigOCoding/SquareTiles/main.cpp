#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, m;
string pic[51];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> pic[i];
}

bool CanPaint(int x, int y) {
    if ((x + 1 < n) && (y + 1 < m)) {
        if ((pic[x][y+1] == '#') && (pic[x+1][y] == '#') && (pic[x+1][y+1] == '#')) {
            pic[x][y] = '/';
            pic[x][y+1] = '\\';
            pic[x+1][y] = '\\';
            pic[x+1][y+1] = '/';
            return true;
        }
    }
    return false;
}

void SolveTestCases() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (pic[i][j] == '#') {
                if (CanPaint(i,j))
                    continue;
                else {
                    cout << "Impossible";
                    return;
                }
            }
        }
    }
    for (int i=0; i<n-1; i++)
        cout << pic[i] << '\n';
    cout << pic[n-1];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m;
        ReadData();
        cout << "Case #" << i << ": " << '\n';
        SolveTestCases();
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
