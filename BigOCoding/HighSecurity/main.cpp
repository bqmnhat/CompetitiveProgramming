#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,ans;
string grid[2];

void ReadData() {
    for (int i=0; i<2; i++)
        cin >> grid[i];
}

bool IsSeparated(int i, int j) {
    if (grid[i][j] != '.') return false;
    if (j == 0) return (grid[i][j+1] == 'X');
    if (j == n-1) return (grid[i][j-1] == 'X');
    return ((grid[i][j+1] == 'X') && (grid[i][j-1] == 'X'));
}

bool PutGuard(int i, int j) {
    if (grid[i][j] != '.') return false;
    ans++;
    if (grid[1^i][j] != 'X') grid[1^i][j] = 'G';
    for (int l = j; l>=0; l--) {
        if (grid[i][l] == 'X')
            break;
        grid[i][l] = 'G';
    }
    for (int r = j; r < n; r++) {
        if (grid[i][r] == 'X')
            break;
        grid[i][r] = 'G';
    }
    return true;
}

int Solution() {
    ans = 0;
    for (int i=0; i<2; i++) {
        for (int j=0; j<n; j++) {
            if (IsSeparated(i,j))
                PutGuard(1 - i, j) || PutGuard(i, j);
        }
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j] == '.')
                PutGuard(i,j);
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << "Case #" << i << ": " << Solution() << '\n';
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
