#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s,ans;
int k, l = 1;

void Solve(int k) {
    for (int i=1; i<=1000000; i++) {
        ans += '0';
    }
    ans[1] = s[0];
    for (int i=1; i<s.length(); i++) {
        while ((s[i] > ans[l]) && (k > 0) && (l>=1)) {
            l--;
            k--;
        }
        l++;
        ans[l] = s[i];
    }
}

void Print() {
    for (int i=1; i<=s.length()-k; i++) {
        cout << ans[i];
    }
}

int main()
{
    freopen("DIGIT.INP", "r", stdin);
    freopen("DIGIT.OUT", "w", stdout);
    cin >> s >> k;
    Solve(k);
    Print();
    return 0;
}
