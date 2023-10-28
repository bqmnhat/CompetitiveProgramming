#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int k, l, color[27];
string s;

int Solution() {
    int ans = 2000000000, i = 0, j = 0, mau = 1;
    color[s[i] - 'a'] = 1;
    while ((i<l) && (j<l)) {
        if (mau >= k) {
            if (j-i+1 < ans)
                ans = j-i+1;
            if (color[s[i] - 'a'] == 1) {
                mau = mau - 1;
            }
            color[s[i] - 'a'] = color[s[i] - 'a'] - 1;
            i++;
        }
        else {
            j++;
            if (j == l)
                break;
            if (color[s[j] - 'a'] == 0)
                mau++;
            color[s[j] - 'a']++;
        }
    }
    if (ans == 2000000000)
        return -1;
    return ans;
}

int main()
{
    freopen("BEADS.INP", "r", stdin);
    freopen("BEADS.OUT", "w", stdout);
    cin >> s >> k;
    l = s.length();
    cout << Solution();
    return 0;
}
