#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[200001], b[200001], a0[100001], a1[100001], b0[100001], b1[100001],m,n,OneA = 0, OneB = 0,x = 0,y = 0;

void ReadData() {
    cin >> m;
    for (int i=1; i<=m; i++) {
        cin >> a[i];
        if (a[i] == 1)
            OneA++;
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        if (b[i] == 1)
            OneB++;
    }
}

void GroupA() {
    int zero = 0, one = OneA;
    for (int i=1; i<=m; i++) {
        if (a[i] == 0) {
            zero++;
        }
        else {
            x++;
            a0[x] = zero;
            a1[x] = one;
            one--;
        }
    }
}

void GroupB() {
    int zero = 0, one = OneB;
    for (int i=1; i<=n; i++) {
        if (b[i] == 0) {
            zero++;
        }
        else {
            y++;
            b0[y] = zero;
            b1[y] = one;
            one--;
        }
    }
}

void Solve() {
    GroupA();
    GroupB();
    int ans = 0,tmp;
    for (int i=1; i<=x; i++) {
        for (int j=1; j<=y; j++) {
            tmp = min(a0[i], b0[j]) + min(a1[i], b1[j]);
            if (tmp > ans)
                ans = tmp;
        }
    }
    cout << ans;
}

int main()
{
    freopen("ABINLIS.INP", "r", stdin);
    freopen("ABINLIS.OUT", "w", stdout);
    ReadData();
    Solve();
    return 0;
}
