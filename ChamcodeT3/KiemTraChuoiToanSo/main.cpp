#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

bool NumberString() {
    for (int i=0; i<s.length(); i++) {
        if ((s[i] < '0') || (s[i]  > '9'))
            return false;
    }
    return true;
}

int main()
{
    cin >> s;
    if (!NumberString())
        cout << "FALSE";
    else
        cout << "TRUE";
    return 0;
}
