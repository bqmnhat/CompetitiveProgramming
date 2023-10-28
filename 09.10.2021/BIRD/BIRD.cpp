#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, h[50001], lh = 0;
string a[11];

void ReadData() {
    for (int i=1; i<=10; i++) {
        cin >> a[i];
    }
}

void PrintAns() {
    cout << lh << '\n';
    for (int i=lh; i>=1; i--) {
        cout << h[i] << " " << 1 << '\n';
    }
}

bool DFS(int i, int j) {
    if (a[i][j] == 'X')
        return false;
    if (j == n-1)
        return true;
    a[i][j] = 'X';
    if (DFS(max(i-1,1), j+1)) {
        lh++;
        h[lh] = j;
        return true;
    }
    if (DFS(min(i+1, 10), j+1))
        return true;
}

int main()
{
    freopen("BIRD.INP", "r", stdin);
    freopen("BIRD.OUT", "w", stdout);
    cin >> n;
    ReadData();
    if (DFS(10,0))
        PrintAns();
    return 0;
}
