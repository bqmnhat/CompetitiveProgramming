#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int f[1001][1001], tv[1001][1001];
bool DelPos[1001];

void Print() {
    for (int i=0; i< s.length(); i++) {
        if (DelPos[i] == false)
            cout << s[i];
    }
}

void Solve() {
    int l = s.length()-1;
    for (int i=l-1; i>=0; i--) {
        for (int j=i+1; j<=l; j++) {
            if ((s[i] == s[j]) or (s[i] == s[j] + 32) or (s[i] == s[j] - 32)) {
                f[i][j] = f[i+1][j-1];
                tv[i][j] = 0;
            }
            else {
                if (f[i+1][j] < f[i][j-1]) {
                    f[i][j] = f[i+1][j] + 1;
                    tv[i][j] = 1;
                }
                else {
                    tv[i][j] = -1;
                    f[i][j] = f[i][j-1] + 1;
                }
            }
        }
    }
    int i=0, j=l;
    while (f[i][j] != 0) {
        if (tv[i][j] == 0) {
            i++;
            j--;
        }
        else if (tv[i][j] == -1) {
            DelPos[j] = true;
            j--;
        }
        else if (tv[i][j] == 1){
            DelPos[i] = true;
            i++;
        }
    }
    Print();
}

int main()
{
    freopen("PALINDROM.INP", "r", stdin);
    freopen("PALINDROM.OUT", "w", stdout);
    cin >> s;
    Solve();
    return 0;
}

