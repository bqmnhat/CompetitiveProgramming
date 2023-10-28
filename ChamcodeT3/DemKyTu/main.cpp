#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
char a;
long long tk[256];

void Solve() {
    for (int i = 0; i<s.length(); i++) {
        tk[s[i]]++;
    }
    cout << tk[a];
}

int main()
{
    getline(std::cin, s);
    cin >> a;
    Solve();
    return 0;
}
