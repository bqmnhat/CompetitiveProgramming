#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

void Solve() {
    for (int i=0; i<s.length(); i++) {
        if ((s[i] == '.') || (s[i] == '?') || (s[i] == '!') || (s[i] == ' ')) {
            cout << s[i];
            continue;
        }
        if ((i == 0) && (s[i] <= 'z') && (s[i] >= 'a')) {
            cout << char(s[i] - ('a' - 'A'));
            continue;
        }
        if ((s[i] <= 'Z') && (s[i] >= 'A')) {
            cout << char(s[i] + ('a' - 'A'));
            continue;
        }
        cout << s[i];
    }
}

int main()
{
    getline(std::cin, s);
    Solve();
    return 0;
}
