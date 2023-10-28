#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int ans = 0;

int main()
{
    getline(std::cin, s);
    s = " " + s;
    for (int i=0; i<s.length()-1; i++)
        if ((s[i-1] == ' ') && (s[i] != ' '))
            ans++;
    cout << ans;
    return 0;
}
