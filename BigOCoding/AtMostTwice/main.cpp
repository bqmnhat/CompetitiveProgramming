#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string U, L, cur_val;
bool Found;
int cnt[10];

void BackTrack(string s, int idx, bool IsSmaller) {
    if (Found)
        return;
    if (idx == s.length()) {
        L = cur_val;
        Found = true;
        return;
    }
    char x = s[idx];
    if (IsSmaller)
        x = '9';
    for (char i = x; i>='0' && !Found; i--) {
        if (cnt[i-'0'] < 2) {
            cnt[i-'0']++;
            cur_val = cur_val + i;
            BackTrack(s, idx+1, IsSmaller | (i < s[idx]));
            cur_val.pop_back();
            cnt[i-'0']--;
        }
    }
}

void Solve() {
    while (cin >> U) {
        L = "";
        cur_val = "";
        Found = false;
        for (int i=0; i<=9; i++)
            cnt[i] = 0;
        BackTrack(U, 0, false);
        reverse(L.begin(), L.end());
        while (L.back() == '0')
            L.pop_back();
        reverse(L.begin(), L.end());
        cout << L << '\n';
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
