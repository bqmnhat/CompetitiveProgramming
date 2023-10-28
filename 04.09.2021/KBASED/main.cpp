#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

void Sum(int &ans, int & Max) {
    ans = 0, Max = 1;
    for (int i=0; i<s.length(); i++) {
        if ((s[i] <= '9') && (s[i] >= '0')) {
            if ((s[i] - '0') > Max)
                Max = s[i] - '0';
            ans = ans + (s[i] - '0');
        }
        else if ((s[i] <= 'Z') && (s[i] >= 'A')) {
            if (((s[i] - 'A') + 10) > Max)
                Max = (s[i] - 'A') + 10;
            ans = ans + ((s[i] - 'A') + 10);
        }
    }
}

void Solve() {
    int Max, tmp;
    Sum(tmp, Max);
    while ((Max < 36) && (tmp % Max != 0)) {
        Max++;
    }
    if ((Max + 1 < 2) || (Max+1 > 36))
        cout << "No solution.";
    else
        cout << Max+1;
}

int main()
{
    freopen("KBASED.INP", "r", stdin);
    freopen("KBASED.OUT", "w", stdout);
    cin >> s;
    Solve();
    return 0;
}
