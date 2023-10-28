#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,k,n;
string Board[3000];

//Debug purpose
void PrintBoard() {
    for (int i=0; i<n; i++)
        cout << Board[i] << '\n';
}

//Solution purpose
void ReadData() {
    for (int i=0; i<n; i++)
        cin >> Board[i];
}

void GravitySimulationShift() {
    for (int i=0; i<n; i++) {
        for (int j=n-1; j>=0; j--) {
            if (Board[i][j] != '.') {
                int m = j;
                while ((m+1 < n) && (Board[i][m+1] == '.'))
                    m++;
                swap(Board[i][m],Board[i][j]);
            }
        }
    }
}

bool IsWinning(int x, int y, int k) {
    int i = x, j = y, Cnt = 0;
    while ((i>=0) && (Board[i][j] == Board[x][y])) {
        Cnt++;
        i--;
    }
    i = x;
    while ((i<n) && (Board[i][j] == Board[x][y])) {
        Cnt++;
        i++;
    }
    if (Cnt-1 >= k)
        return true;
    i = x;
    Cnt = 0;
    while ((j>=0) && ((Board[i][j] == Board[x][y]))) {
        Cnt++;
        j--;
    }
    j = y;
    while ((j<n) && (Board[i][j] == Board[x][y])) {
        Cnt++;
        j++;
    }
    if (Cnt-1 >= k)
        return true;
    j = y;
    Cnt = 0;
    while ((i>=0) && (j>=0) && (Board[i][j] == Board[x][y])) {
        Cnt++;
        i--;
        j--;
    }
    i = x;
    j = y;
    while ((i<n) && (j<n) && (Board[i][j] == Board[x][y])) {
        Cnt++;
        i++;
        j++;
    }
    if (Cnt-1 >= k)
        return true;
    i = x;
    j = y;
    Cnt = 0;
    while ((i>=0) && (j<n) && (Board[i][j] == Board[x][y])) {
        Cnt++;
        i--;
        j++;
    }
    i = x;
    j = y;
    while ((i<n) && (j>=0) && (Board[i][j] == Board[x][y])) {
        Cnt++;
        i++;
        j--;
    }
    if (Cnt-1 >= k)
        return true;
    return false;
}

void CheckWinner() {
    bool Red = false, Blue = false;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ((Board[i][j] == 'R') && (IsWinning(i,j,k)))
                Red = true;
            if ((Board[i][j] == 'B') && (IsWinning(i,j,k)))
                Blue = true;
        }
    }
    if ((Blue == true) && (Red == true))
        cout << "Both";
    else if (Blue == true)
        cout << "Blue";
    else if (Red == true)
        cout << "Red";
    else
        cout << "Neither";
}

void Init() {
    for (int i=0; i<3000; i++)
        Board[i] = "";
}

void Solve() {
    for (int i=1; i<=t; i++) {
        Init();
        cin >> n >> k;
        ReadData();
        GravitySimulationShift();
        cout << "Case #" << i << ": ";
        CheckWinner();
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
