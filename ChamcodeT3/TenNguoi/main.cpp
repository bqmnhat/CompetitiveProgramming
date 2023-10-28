#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s,s1;

void Solve() {
    int i = s.length()-1;
    while ((s[i] != ' ') && (i >= 0)) {
        s1 = s[i] + s1;
        i--;
    }
    cout << s1;
}

int main()
{
    getline(std::cin, s);
    Solve();
    return 0;
}
