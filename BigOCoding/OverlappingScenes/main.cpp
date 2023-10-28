#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T, n, a[7];
string s[7];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> s[i];
}

string CombStr(string a, string b) {
    int i = 0, j = 0, la = a.length(), lb = b.length();
    string Ans = "";
    while ((i < la) && (a[i] != b[j])) {
        Ans = Ans + a[i];
        i++;
    }
    while ((i < la) && (j < lb) && (a[i] == b[j])) {
        Ans = Ans + a[i];
        i++;
        j++;
    }
    if (i >= la)
        while (j < lb) {
            Ans = Ans + b[j];
            j++;
        }
    else
        Ans = a + b;
    return Ans;
}

int MaxLenOfFilm() {
    for (int i=1; i<=n; i++)
        a[i] = i;
    int MaxLen = 0;
    string tmp = "";
    while (next_permutation(a+1, a+1+n)) {
        for (int i=1; i<=n; i++) {
            tmp = CombStr(tmp, s[a[i]]);
        }
    }
}

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> n;
        ReadData();
        cout << MaxLenOfFilm();
    }
}

int main()
{
    cout << CombStr("ABCD", "CDEF");
    return 0;
}
