#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m, s;

bool DigitsAvailable(int s, int m) {
    return ((s >= 0) && (s <= 9*m));
}

void PrintMin(int s, int m) {
    bool Found;
    string ans = "";
    for (int i=1; i<=m; i++) {
        for (int dig = 0; dig <= 9; dig++) {
            Found = false;
            if (((i > 1) || (dig > 0) || ((m==1) && (dig==0))) && (DigitsAvailable(s - dig, m - i))) {
                Found = true;
                ans = ans + char(dig + '0');
                s = s - dig;
                break;
            }
        }
        if (!Found) {
            cout << "-1";
            return;
        }
    }
    cout << ans;
}

void PrintMax(int s, int m) {
    bool Found;
    string ans = "";
    for (int i=1; i<=m; i++) {
        for (int dig = 9; dig >= 0; dig--) {
            Found = false;
            if (((i > 1) || (dig > 0) || ((m==1) && (dig==0))) && (DigitsAvailable(s - dig, m - i))) {
                Found = true;
                ans = ans + char(dig + '0');
                s = s - dig;
                break;
            }
        }
        if (!Found) {
            cout << "-1";
            return;
        }
    }
    cout << ans;
}

int main()
{
    cin >> m >> s;
    PrintMin(s,m);
    cout << ' ';
    PrintMax(s,m);
    return 0;
}
