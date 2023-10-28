#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int k, Left[1001], Right[1001], st[1001], lst = 0;

void MakeLeft() {
    Left[0] = s[0];
    for (int i=1; i<s.length(); i++) {
        if (s[i-1] != s[i])
            Left[i] = s[i-1];
        else
            Left[i] = Left[i-1];
    }
}

void MakeRight() {
    Right[s.length()-1] = s[s.length()-1];
    for (int i=s.length()-2; i>=0; i--) {
        if (s[i+1] != s[i])
            Right[i] = s[i+1];
        else
            Right[i] = Right[i+1];
    }
}

void Solve() {
    string MaxAns;
    char MinChar = 'z';
    for (int i=0; i<s.length(); i++) {
        if (s[i] < MinChar)
            MinChar = s[i];
    }
    for (int i=0; i<s.length(); i++) {
        if (s[i] == MinChar) {
            lst++;
            st[lst] = i;
        }
    }
    bool Found = false;
    int l = s.length();
    string TmpAns;
    for (int i=1; i<=lst; i++) {
        TmpAns = "";
        int j =  st[i];
        TmpAns = TmpAns + s[j];
        int x = k;
        while (x-1 > 0) {
            x--;
            if (j - 1 < 0) {
                j++;
                TmpAns = TmpAns + s[j];
                continue;
            }
            if (j + 1 > l - 1) {
                j--;
                TmpAns = TmpAns + s[j];
                continue;
            }
            if (s[j-1] < s[j+1])
                j--;
            else if (s[j+1] < s[j-1])
                j++;
            else if (s[j+1] == s[j-1]) {
                if (Right[j] < Left[j])
                    j++;
                else
                    j--;
            }
            TmpAns = TmpAns + s[j];
        }
        if ((TmpAns < MaxAns) || (Found == false)) {
            MaxAns = TmpAns;
            Found = true;
        }
    }
    cout << MaxAns;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> k;
    MakeLeft();
    MakeRight();
    Solve();
    return 0;
}
