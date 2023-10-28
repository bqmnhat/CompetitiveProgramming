#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int n;
string s;

int Solution() {
    int ans = 0, cnt = 0;
    n = s.length();
    for (int i=0; i<n; i++) {
        if (s[i] != s[i-1])
            cnt = 0;
        cnt++;
        ans = max(ans, cnt);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cout << Solution();
    return 0;
}
