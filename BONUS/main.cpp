#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s[100001], mau = "TRUNGTUYEN2021";
int n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        getline(cin,s[i]);
    }
}

void Solve() {
    int ans, l;
    for (int i=1; i<=n; i++) {
        ans = 0;
        l = 0;
        for (int j=0; j<s[i].length(); j++) {
            if (s[i][j] == ' ')
                continue;
            if (s[i][j] > 'Z') {
                s[i][j] = s[i][j] - 32;
            }
            if (s[i][j] == mau[l]) {
                l++;
            }
            else
                l = 0;
            if (l > 13) {
                ans++;
                l = 0;
            }
        }
        cout << ans << endl;
    }
}

int main()
{
    freopen("BONUS.INP", "r", stdin);
    freopen("BONUS.OUT", "w", stdout);
    cin >> n;
    getchar();
    ReadData();
    Solve();
    return 0;
}
