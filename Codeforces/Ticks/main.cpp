#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int k,n,m,t;
bool a[11][20], tmp[11][20];

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            if (c == '*')
                a[i][j] = true;
        }
    }
}

void InitTmp() {
    for (int i=0; i<=10; i++) {
        for (int j=0; j<=19; j++)
            tmp[i][j] = false;
    }
}

void InitA() {
    for (int i=0; i<=10; i++) {
        for (int j=0; j<=19; j++)
            a[i][j] = false;
    }
}

bool Check(int il, int jl, int ir, int jr) {
    return ((il >= 1) && (jl >= 1) && (ir >= 1) && (jr <= m) && (a[il][jl]) && (a[ir][jr]));
}

int Tick(int mode, int x, int y)  {// mode = 0: check; mode = 1: draw
    int il = x - 1, jl = y - 1, ir = x - 1, jr = y + 1, cnt = 0;
    if (!a[x][y])
        return 0;
    if (mode == 1)
        tmp[x][y] = true;
    while (Check(il,jl,ir,jr)) {
        if (mode == 1)
            tmp[il][jl] = tmp[ir][jr] = true;
        il--;
        jl--;
        ir--;
        jr++;
        cnt++;
    }
    return cnt;
}

bool CheckAns() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[i][j] != tmp[i][j])
                return false;
        }
    }
    return true;
}

void Solve() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (Tick(0,i,j) >= k)
                Tick(1,i,j);
        }
    }
    if (CheckAns())
        cout << "YES";
    else
        cout << "NO";
    cout << '\n';
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        InitTmp();
        InitA();
        cin >> n >> m >> k;
        ReadData();
        Solve();
    }
    return 0;
}
