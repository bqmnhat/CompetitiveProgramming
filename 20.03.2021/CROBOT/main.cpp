#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string cmd;

void Solve() {
    char NCmd;
    int i = 0, j = 0, Dir = 1;
    for (int x=0; x<n; x++) {
        NCmd = cmd[x];
        if (Dir == 1) {
            if (NCmd == 'R') {
                j++;
                Dir = 2;
            }
            if (NCmd == 'L') {
                j--;
                Dir = 4;
            }
            if (NCmd == 'B') {
                i--;
                Dir = 3;
            }
            if (NCmd == 'G') {
                i++;
            }
        }
        else if (Dir == 2) {
            if (NCmd == 'R') {
                i--;
                Dir = 3;
            }
            if (NCmd == 'L') {
                ++i;
                Dir = 1;
            }
            if (NCmd == 'B') {
                j--;
                Dir = 4;
            }
            if (NCmd == 'G') {
                j++;
            }
        }
        else if (Dir == 3) {
            if (NCmd == 'R') {
                j--;
                Dir = 4;
            }
            if (NCmd == 'L') {
                j++;
                Dir = 2;
            }
            if (NCmd == 'B') {
                i++;
                Dir = 1;
            }
            if (NCmd == 'G') {
                i--;
            }
        }
        else if (Dir == 4) {
            if (NCmd == 'R') {
                i++;
                Dir = 1;
            }
            if (NCmd == 'L') {
                i--;
                Dir = 3;
            }
            if (NCmd == 'B') {
                j++;
                Dir = 2;
            }
            if (NCmd == 'G') {
                j--;
            }
        }
    }
    cout << j << " " << i;
}

int main()
{
    freopen("CROBOT.INP", "r", stdin);
    freopen("CROBOT.OUT", "w", stdout);
    cin >> n >> cmd;
    Solve();
    return 0;
}
