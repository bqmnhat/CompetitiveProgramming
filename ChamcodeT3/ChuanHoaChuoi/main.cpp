#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

void Solve() {
    bool exist = false;
    for (int i=0; i<s.length(); i++) {
        if  (s[i] != '/') {
            if ((s[i-1] == '/') && (exist))
                cout << s[i-1];
            cout << s[i];
            exist = true;
        }
    }
}

int main()
{
    getline(std::cin, s);
    Solve();
    return 0;
}
