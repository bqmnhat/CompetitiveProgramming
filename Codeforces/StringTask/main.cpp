#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
bool vowel[256];

void MakeVowel() {
    vowel['U'] = vowel['u'] = vowel['E'] = vowel['e'] = vowel['O'] = vowel['o'] = vowel['A'] = vowel['a'] = vowel['I'] = vowel['i'] = vowel['Y'] = vowel['y'] = true;
}

void Solve() {
    for (int i=0; i<s.length(); i++) {
        if (vowel[s[i]])
            continue;
        else {
            cout << '.';
            int tmp = 'a' - 'A';
            char c;
            if ((s[i] >= 'A') && (s[i] <= 'Z'))
                c = char(s[i] + tmp);
            else
                c = s[i];
            cout << c;
        }
    }
}

int main()
{
    cin >> s;
    MakeVowel();
    Solve();
    return 0;
}
