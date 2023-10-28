#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T, x, pow10[201], a[202][202];

void MakePow() {
    pow10[0] = 1;
    for (int i=1; i<=200; i++) {
        pow10[i] = ((pow10[i-1]%x)*(10%x))%x;
    }
}

void Init() {
    for (int i=0; i<=200; i++)
        for (int j=0; j<=200; j++)
            a[i][j] = -1;
}

void PrintAns(int Cnt8, int Cnt6) {
    for (int i=1; i<=Cnt8; i++)
        cout << "8";
    for (int i=1; i<=Cnt6; i++)
        cout << "6";
}

void MakeA() {
    a[0][0] = 0;
    int tmp = 401, ansi = -1, ansj = -1;
    for (int j=1; j<=200; j++)
        a[0][j] = (a[0][j-1]*10 + 6)%x;
    for (int i=1; i<=200; i++)
        a[i][0] = (8*pow10[i-1] + a[i-1][0])%x;
    for (int i=1; i<=200; i++) {
        for (int j=1; j<=200; j++) {
            a[i][j] = (a[i][j-1]*10 + 6)%x;
        }
    }
    for (int i=0; i<=200; i++) {
        for (int j=0; j<=200; j++) {
            if ((i == 0) && (j == 0))
                continue;
            if ((a[i][j] == 0) && (i+j < tmp) && (i+j <= 200)) {
                tmp = i+j;
                ansi = i;
                ansj = j;
            }
        }
    }
    if (ansi == -1)
        cout << "-1";
    else
        PrintAns(ansi, ansj);
}

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> x;
        Init();
        MakePow();
        MakeA();
        cout << '\n';
    }
}

int main()
{
    freopen("NUM86.INP", "r", stdin);
    freopen("NUM86.OUT", "w", stdout);
    cin >> T;
    Solve();
    return 0;
}
