#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string a[9];

void ReadData() {
    for (int i=1; i<=6; i++) {
        for (int j = 1; j<=9; j++)
            cin >> a[i][j];
    }
}

int VerticalCnt(char x,char y,char z) {
    int ans = 0;
    for (int i = 1; i<=9; i++) {
        for (int j = 1; j<=6; j++) {
            if ((i>=1) && (i<=3) && (a[j][i] != x))
                ans++;
            if ((i>=4) && (i<=6) && (a[j][i] != y))
                ans++;
            if ((i>=7) && (i<=9) && (a[j][i] != z))
                ans++;
        }
    }
    return ans;
}

int HorizontalCnt(char x,char y,char z) {
    int ans = 0;
    for (int i = 1; i<=6; i++) {
        for (int j = 1; j<=9; j++) {
            if ((i>=1) && (i<=2) && (a[i][j] != x))
                ans++;
            if ((i>=3) && (i<=4) && (a[i][j] != y))
                ans++;
            if ((i>=5) && (i<=6) && (a[i][j] != z))
                ans++;
        }
    }
    return ans;
}

int FlagDist() {
    int VerDist = 54, HorDist = 54;
    for (char x = 'A'; x <= 'Z'; x++)
        for (char y = 'A'; y <= 'Z'; y++)
            for(char z = 'A'; z <= 'Z'; z++)
                if((x!=y) && (y!=z)) {
                    VerDist = min(VerDist, VerticalCnt(x,y,z));
                    HorDist = min(HorDist, HorizontalCnt(x,y,z));
                }
    return min(VerDist,HorDist);
}

int main()
{
    freopen("FLAG.INP", "r", stdin);
    freopen("FLAG.OUT", "w", stdout);
    ReadData();
    cout << FlagDist();
    return 0;
}
