#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char a[7][10];

void ReadData() {
    for (int i=1; i<=6; i++) {
        for (int j=1; j<=9; j++) {
            cin >> a[i][j];
        }
    }
}

int CountHorizontal(char x, char y, char z) {
    int ans = 0;
    for (int i=1; i<=6; i++) {
        for (int j=1; j<=9; j++) {
            if ((i>=1) && (i<=2) && (a[i][j] != x)) {
                ans++;
            }
            if ((i>=3) && (i<=4) && (a[i][j] != y)) {
                ans++;
            }
            if ((i>=5) && (i<=6) && (a[i][j] != z)) {
                ans++;
            }
        }
    }
    return ans;
}

int CountVertical(char x, char y, char z) {
    int ans = 0;
    for (int j=1; j<=9; j++) {
        for (int i=1; i<=6; i++) {
            if ((j>=1) && (j<=3) && (a[i][j] != x)) {
                ans++;
            }
            if ((j>=4) && (j<=6) && (a[i][j] != y)) {
                ans++;
            }
            if ((j>=7) && (j<=9) && (a[i][j] != z)) {
                ans++;
            }
        }
    }
    return ans;
}

void Solve() {
    int VerDist = 54, HorDist = 54;
    for (char x = 'A'; x<='Z'; x++) {
        for (char y = 'A'; y<='Z'; y++) {
            for (char z = 'A'; z<='Z'; z++) {
                if ((x != y) && (z != y)) {
                    VerDist = min(VerDist, CountVertical(x,y,z));
                    HorDist = min(HorDist, CountHorizontal(x,y,z));
                }
            }
        }
    }
    cout << min(VerDist, HorDist);
}

int main()
{
    freopen("FLAG_ONTAP.INP", "r", stdin);
    freopen("FLAG_ONTAP.OUT", "w", stdout);
    ReadData();
    Solve();
    return 0;
}
