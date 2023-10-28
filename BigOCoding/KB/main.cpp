#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int tk[257], n;

int Solution() {
    int ans = 0, cnt = 0;
    for (int i=0; i<s.length(); i++) {
        tk[s[i]]++;
        if (tk[s[i]] == 1)
            cnt++;
    }
    for (int i=1; i<=256; i++)
        if (tk[i] > 1)
            ans = ans + (tk[i] - 1);
    if (ans > (26-cnt))
        return -1;
    return ans;
}

int main()
{
    cin >> n >> s;
    cout << Solution();
    return 0;
}
