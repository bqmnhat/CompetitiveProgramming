#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[50];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
}

int LowestEmptyRow(int x, int col) {
    while ((x+1 < n) && (s[x+1][col] == '.'))
        x++;
    return x;
}

void Solve() {
    for (int i=n-1; i>=0; i--) {
        for (int j=0; j<m; j++) {
            if ((s[i][j] == '#') || (s[i][j] == '.'))
                continue;
            int MoveTo = LowestEmptyRow(i, j);
            swap(s[MoveTo][j],s[i][j]);
        }
    }
    for (int i=0; i<n; i++)
        cout << s[i] << '\n';
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
