#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string x, s;
long long f[3][100001];

long long Solution() {
    for (int i=0; i<x.length(); i++) {
        if (s[0] == x[i]) {
            f[0][i] = f[0][i-1]+1;
        }
        else
            f[0][i] = f[0][i-1];
    }
    for (int i=1; i<s.length(); i++) {
        for (int j=0; j<x.length(); j++) {
            if (s[i] == x[j]) {
                f[i][j] = f[i][j-1] + f[i-1][j-1];
            }
            else
                f[i][j] = f[i][j-1];
        }
    }
    return f[s.length()-1][x.length()-1];
}

int main()
{
    cin >> x >> s;
    cout << Solution();
    return 0;
}
