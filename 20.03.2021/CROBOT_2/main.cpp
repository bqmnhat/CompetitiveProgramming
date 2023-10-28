#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, dx[4] = {-1,0,1,0}, dy[4] = {0,1,0,-1};
string cmd;

void Solve() {
    int x = 0, y = 0, t = 1;
    for (int i=0; i<cmd.length(); i++) {
        if (cmd[i] == 'R')
            t = (t+1)%4;
        else if (cmd[i] == 'L')
            t = (t+3)%4;
        else if (cmd[i] == 'B')
            t = (t+2)%4;
        x = x + dx[t];
        y = y + dy[t];
    }
    cout << x << " " << y;
}

int main()
{
    freopen("CROBOT.INP", "r", stdin);
    freopen("CROBOT.OUT", "w", stdout);
    cin >> n >> cmd;
    Solve();
    return 0;
}

