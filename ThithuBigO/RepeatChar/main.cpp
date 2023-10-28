#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int tk[256];

void FindRepeat() {
    for (int i=0; i<s.length(); i++) {
        tk[s[i]]++;
        if (tk[s[i]] == 2) {
            cout << s[i];
            return;
        }
    }
    cout << "null";
}

int main()
{
    cin >> s;
    FindRepeat();
    return 0;
}
