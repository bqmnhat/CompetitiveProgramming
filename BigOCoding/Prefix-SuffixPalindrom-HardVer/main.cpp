#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int t, pref[MaxN+1];
string s;
ll PowOfB[MaxN+1];
const ll Base = 31, Mod = 1e15 + 11; //hash failed because of false coincidences

string LPS(string s) {
    string x = s;
    reverse(x.begin(), x.end());
    x = s + "#" + x;
    int tmp = 0, l = x.length();
    for (int i=1; i<l; i++) {
        while ((tmp != 0) && (x[tmp] != x[i]))
            tmp = pref[tmp-1];
        if (x[tmp] == x[i])
            tmp++;
        pref[i] = tmp;
    }
    return s.substr(0, tmp);
}

void SolveTestCase() {
    int k = 0, l = s.length();
    while ((k < l-k-1) && (s[k] == s[l-k-1]))
        k++;
    if (k > 0)
        cout << s.substr(0, k);
    if (l > 2*k) {
        string midd = s.substr(k, l-2*k);
        string a = LPS(midd);
        reverse(midd.begin(), midd.end());
        string b = LPS(midd);
        if (a.length() < b.length())
            cout << b;
        else
            cout << a;
    }
    if (k > 0)
        cout << s.substr(l-k, k);
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
