#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,m;
string s;

bool CheckXY(int xy, int maxxy, int minxy, int limit) {
    return ((xy <= limit) && (xy >= 1) && (xy + maxxy <= limit) && (xy + minxy >= 1));
}

void SolveTestCases() {
    int mindx = 0, maxdx = 0, mindy = 0, maxdy = 0, dx = 0, dy = 0, x = 1, y = 1;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == 'L')
            dy--;
        mindy = min(mindy, dy);
        if (s[i] == 'R')
            dy++;
        maxdy = max(maxdy, dy);
        if (s[i] == 'U')
            dx--;
        mindx = min(mindx, dx);
        if (s[i] == 'D')
            dx++;
        maxdx = max(maxdx, dx);
        int xx = n - maxdx, yy = m - maxdy;
        if ((CheckXY(xx, maxdx, mindx, n)) && (CheckXY(yy, maxdy, mindy, m))) {
            x = xx;
            y = yy;
        }
        else
            break;
    }
    cout << x << " " << y << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> m >> s;
        SolveTestCases();
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
