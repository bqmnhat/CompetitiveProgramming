#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s1,s2;

void LowerAllCase() {
    for (int i=0; i<s1.length(); i++) {
        if ((s1[i] <= 'Z') && (s1[i] >= 'A'))
            s1[i] = char(s1[i] + ('a' - 'A'));
    }
    for (int i=0; i<s2.length(); i++) {
        if ((s2[i] <= 'Z') && (s2[i] >= 'A'))
            s2[i] = char(s2[i] + ('a' - 'A'));
    }
}

int Solution() {
    int ans = 0;
    for (int i=0; i<s1.length(); i++) {
        bool exist = true;
        for (int j=0; j<s2.length(); j++) {
            if (s1[i+j] != s2[j]) {
                exist = false;
                break;
            }
        }
        if (exist)
            ans++;
    }
    return ans;
}

int main()
{
    getline(std::cin,s1);
    getline(std::cin,s2);
    LowerAllCase();
    cout << Solution();
    return 0;
}
