#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[10], t[10], ans = 0;
int x[10][10] =
{
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,0,1,0,0,0,0,0},
    {0,1,1,1,0,1,0,0,0,0},
    {0,0,1,1,0,0,1,0,0,0},
    {0,1,0,0,1,1,0,1,0,0},
    {0,1,0,1,0,1,0,1,0,1},
    {0,0,0,1,0,1,1,0,0,1},
    {0,0,0,0,1,0,0,1,1,0},
    {0,0,0,0,0,1,0,1,1,1},
    {0,0,0,0,0,0,1,0,1,1}
};

bool Check() {
    int b[10];
    for (int i=1; i<=9; i++) {
        b[i] = a[i];
    }
    for (int i=1; i<=9; i++) {
        for (int j=1; j<=9; j++) {
            if (x[i][j] == 1)  {
                b[i] = (b[i] + t[j])%4;
            }
        }
        if (b[i] != 0)
            return false;
    }
    return true;
}

void Sol() {
    int ans = 0;
    for (int i=1; i<=9; i++)
        ans = ans + t[i];
    cout << ans << endl;
    for (int i=1; i<=9; i++) {
        for (int j=1; j<=t[i]; j++) {
            cout << i << endl;
        }
    }
    exit(0);
}

void Try(int i) {
    for (int v=0; v<=3; v++) {
        t[i] = v;
        if (i == 9) {
            if (Check() == true) {
                Sol();
            }
        }
        else Try(i+1);
    }
}

void ReadData() {
    for (int i=1; i<=9; i++) {
        cin >> a[i];
    }
}

int main()
{
    freopen("CLOCKS.INP", "r", stdin);
    freopen("CLOCKS.OUT", "w", stdout);
    ReadData();
    Try(1);
    return 0;
}
