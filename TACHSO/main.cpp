#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

bool CmpLess(string a, string b) {
    while (a.length() < b.length())
        a = '0' + a;
    while (b.length() < a.length())
        b = '0' + b;
    return (a < b);
}

void Solve() {
    int l = s.length(), la = 0;
    string ans[10001];
    for (int i=0; i<l; i++) {
        if (s[i] == '0')
            ans[la] = ans[la] + '0';
        else if ((la >= 2) && (CmpLess(ans[la], ans[la-1])))
            ans[la] = ans[la] + s[i];
        else {
            la++;
            ans[la] = s[i];
        }
    }
    while (CmpLess(ans[la], ans[la-1]))
        la--;
    cout << la << '\n';
    for (int i=1; i<la; i++)
        cout << ans[i] << ' ';
    int tmp = ans[la].length(), i = -1;
    string last = "";
    do {
        i++;
        last = last + ans[la][i];
    } while (((ans[la][i+1] != '0') || (CmpLess(last, ans[la-1]))) && (i < tmp));
    cout << last;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TACHSO.INP", "r", stdin);
    freopen("TACHSO.OUT", "w", stdout);
    cin >> s;
    Solve();
    return 0;
}
