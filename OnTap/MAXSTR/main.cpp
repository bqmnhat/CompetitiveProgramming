#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int f[1001][1001];

void TruyVet() {
    string ans1 = "", ans2 = "";
    int i=s.length()-1, j=1;
    while (i>j) {
        if (s[i] == s[j]) {
            ans1 = ans1 + s[i];
            ans2 = s[j]+ ans2;
            i--;
            j++;
        }
        else if (f[i][j] == f[i][j+1]) {
            j++;
        }
        else
            i--;
    }
    cout << ans1;
    if (i == j)
        cout << s[i];
    cout << ans2;
}

void Solve() {
    for (int i=1; i<s.length(); i++) {
        for (int j = s.length()-1 ; j>=1; j--) {
            if (s[i] == s[j])
                f[i][j] = f[i-1][j+1] + 1;
            else
                f[i][j] = max(f[i][j+1], f[i-1][j]);
        }
    }
    cout << f[s.length()-1][1] << endl;
    TruyVet();
}

int main()
{
    cin >> s;
    s = " " + s;
    Solve();
    return 0;
}
