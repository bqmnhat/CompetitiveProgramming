#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string strn, strt;
int n, t;

int ValOfStr(string str) {
    int ans = 0;
    bool Start = false;
    for (int i=0; i<str.length(); i++) {
        if ((str[i] == '0') && (!Start))
            continue;
        Start = true;
        ans = ans*10 + int(str[i] - '0');
    }
    return ans;
}

void Solve() {
    n = ValOfStr(strn);
    t = ValOfStr(strt);
    int lenT = strt.length(), p = 1;
    for (int i=1; i<=lenT; i++)
        p = p*10;
    int G = __gcd(t, p);
    if ((t%G == 0) && (p%G == 0)) {
        t = t/G;
        p = p/G;
    }
    int num = n*p + t, de = p;
    cout << num << ' ' << de;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> strn >> strt;
    Solve();
    return 0;
}
