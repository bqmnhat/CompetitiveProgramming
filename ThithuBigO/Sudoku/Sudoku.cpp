#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[10][10];
bool tk1[10][10], tk2[10][10];

bool ReadandCheck() {
    bool ans = true;
    for (int i=1; i<=9; i++) {
        for (int j=1; j<=9; j++) {
            cin >> a[i][j];
            if (tk1[i][a[i][j]] == true) {
                ans = false;
            }
            else
                tk1[i][a[i][j]] = true;
            if (tk2[j][a[i][j]] == true) {
                ans = false;
            }
            else
                tk2[j][a[i][j]] = true;

        }
    }
    return ans;
}

bool Check3x3(int i, int j) {
    bool tk[10];
    for (int i=1; i<=9; i++) {
        tk[i] = false;
    }
    for (int x=i; x<=i+2; x++) {
        for (int y=j; y<=j+2; y++) {
            if (tk[a[x][y]] == true)
                return false;
            else
                tk[a[x][y]] = true;
        }
    }
    return true;
}

bool CheckSudoku() {
    if (ReadandCheck() == false) {
        return false;
    }
    for (int i=0; i<=2; i++) {
        for (int j=0; j<=2; j++) {
            if (Check3x3(i*3+1, j*3+1) == false) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    if (CheckSudoku() == false)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
