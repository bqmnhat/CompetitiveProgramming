#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int t,m,n,p,q;
char a[1001][1001],b[1001][1001];

void ReadData(char d[1001][1001], int x, int y) {
    for (int i = 1; i<=x; i++) {
        for (int j = 1; j<=y; j++)
            cin >> d[i][j];
    }
}

bool IsSame(int i, int j) {
    for (int x = 1; x<=p; x++) {
        for (int y = 1; y<=q; y++) {
            if (a[i+x-1][j+y-1] != b[x][y])
                return false;
        }
    }
    return true;
}

bool FoundGrid() {
    int x = m-p+1, y = n-q+1;
    for (int i=1; i <= x; i++) {
        for (int j = 1; j <= y; j++) {
            if (a[i][j] == b[1][1]) {
                if (IsSame(i,j))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    freopen("GRID.INP", "r", stdin);
    freopen("GRID.OUT", "w", stdout);
    cin >> t;
    for (int i = 1; i<=t; i++) {
        cin >> m >> n;
        ReadData(a,m,n);
        cin >> p >> q;
        ReadData(b,p,q);
        if (FoundGrid())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
