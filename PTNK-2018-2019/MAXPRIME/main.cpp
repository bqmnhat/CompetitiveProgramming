#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
long long a;
int QuPos[3];

long long StrToLL(string s) {
    long long ans = 0;
    for (int i=0; i<s.length(); i++) {
        ans = ans*10 + (s[i] - '0');
    }
    return ans;
}

bool IsPrime(long long x) {
    if (x <= 1) {
        return false;
    }
    else if (x <= 3) {
        return true;
    }
    else if ((x % 2 == 0) or (x % 3 == 0) or (x % 5 == 0)) {
        return false;
    }
    long long i=5, m = sqrt(x);
    while (i <= m) {
        if (x % i == 0)
            return false;
        i += 6;
    }
    i = 7;
    while (i <= m) {
        if (x % i == 0)
            return false;
        i += 6;
    }
    return true;
}

void Solve() {
    int k = 0;
    for (int i = 0; i<s.length(); i++) {
        if (s[i] == '?') {
            k++;
            QuPos[k] = i;
        }
    }
    for (int i=9; i>=0; i--) {
        if ((i == 0) && (QuPos[1] == 0)) {
            continue;
        }
        s[QuPos[1]] = i + '0';
        for (int i=9; i>=0; i--) {
            s[QuPos[2]] = i + '0';
            a = StrToLL(s);
            if (IsPrime(a) == true) {
                cout << s;
                return;
            }
        }
    }
}

int main()
{
    freopen("MAXPRIME.INP", "r", stdin);
    freopen("MAXPRIME.OUT", "w", stdout);
    cin >> s;
    Solve();
    return 0;
}
