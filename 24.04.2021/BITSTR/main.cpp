#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int ans = 0;

void Flip(int st, string& s) {
    for (int i = st; i<=st+3; i++) {
        s[i] = '1' - s[i] + '0';
    }
}

int MinFlip() {
    int flip0 = 0, flip1 = 0, i=0, n = s.length();
    string x1 = s, x2 = s;
    while (i<n) {
        if (x1[i] == '1') {
            if (i >= n-3) {
                flip1 = -1;
                break;
            }
            Flip(i,x1);
            flip1++;
        }
        i++;
    }
    i = 0;
    while (i<n) {
        if (x2[i] == '0') {
            if (i >= n-3) {
                flip0 = -1;
                break;
            }
            Flip(i,x2);
            flip0++;
        }
        i++;
    }
    if ((flip0 == -1) && (flip1 != -1))
        return flip1;
    else if ((flip1 == -1) && (flip0 != -1))
        return flip0;
    else
        return min(flip0, flip1);
}

int main()
{
    freopen("BITSTR.INP", "r", stdin);
    freopen("BITSTR.OUT", "w", stdout);
    cin >> s;
    cout << MinFlip();
    return 0;
}
