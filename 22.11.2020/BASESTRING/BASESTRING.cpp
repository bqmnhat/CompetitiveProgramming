#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int k;
int GCD(int a, int b) {
    int tmp;
    while (b!=0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

bool CheckBase(int k, string s) {
    int x = s.length()/k;
    for (int i = 0; i<k; i++) {
        for (int j = 2; j <= x; j++) {
            if (s[i] != s[i+k*(j-1)])
                return false;
        }
    }
    return true;
}

void Solve() {
    k = GCD(s1.length(), s2.length());
    if ((CheckBase(k,s1) == true) && (CheckBase(k,s2) == true)) {
        for (int i=0; i<k; i++)
            cout << s1[i];
    }
    else
        cout << "NO";
}

int main()
{
    freopen("BASESTRING.INP", "r", stdin);
    freopen("BASESTRING.OUT", "w", stdout);
    cin >> s1 >> s2;
    Solve();
    return 0;
}
