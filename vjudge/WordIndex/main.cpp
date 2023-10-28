#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<string, int> encode;

bool Check(string s) {
    int l = s.length();
    for (int i = 0; i<l-1; i++)
        if (s[i] >= s[i+1])
            return false;
    return true;
}

void MakeEncode() {
    string s = "a";
    int l = 0, id = 0;
    while (l < 5) {
        if (Check(s)) {
            id++;
            encode[s] = id;
        }
        s[l]++;
        int i = l;
        string tmps = s;
        while ((s[i] > 'z') && (i > 0)) {
            s[i-1]++;
            s[i] = 'a';
            i--;
        }
        if (s[0] > 'z') {
            s = 'a' + s;
            l++;
            s[1] = 'a';
        }
    }
}

void Solve() {
    string s;
    while (cin >> s) {
        if (encode.find(s) == encode.end())
            cout << "0\n";
        else
            cout << encode[s] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeEncode();
    Solve();
    return 0;
}
