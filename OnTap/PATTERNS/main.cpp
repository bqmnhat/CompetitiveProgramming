#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool a[256][10];
string s1, s2;

void Init() {
    for (int i=0; i<=9; i++) {
        a['?'][i] = true;
        a[i+'0'][i] = true;
    }
    a['a'][0] = true; a['a'][1] = true; a['a'][2] = true; a['a'][3] = true;
    a['b'][1] = true; a['b'][2] = true; a['b'][3] = true; a['b'][4] = true;
    a['c'][2] = true; a['c'][3] = true; a['c'][4] = true; a['c'][5] = true;
    a['d'][3] = true; a['d'][4] = true; a['d'][5] = true; a['d'][6] = true;
    a['e'][4] = true; a['e'][5] = true; a['e'][6] = true; a['e'][7] = true;
    a['f'][5] = true; a['f'][6] = true; a['f'][7] = true; a['f'][8] = true;
    a['g'][6] = true; a['g'][7] = true; a['g'][8] = true; a['g'][9] = true;
}

long long Solution() {
    long long ans = 1;
    for (int i=0; i<s1.length(); i++) {
        long long tmp = 0;
        for (int j=0; j<=9; j++) {
            if ((a[s1[i]][j] == true) && (a[s2[i]][j] == true))
                tmp++;
        }
        ans = ans*tmp;
    }
    return ans;
}

int main()
{
    freopen("PATTERNS.INP", "r", stdin);
    freopen("PATTERNS.OUT", "w", stdout);
    cin >> s1 >> s2;
    Init();
    cout << Solution();
    return 0;
}
