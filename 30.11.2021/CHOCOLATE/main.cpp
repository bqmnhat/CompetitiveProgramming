#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

long long Solution() {
    int n = s.length();
    long long cnt = 0, ans = 1;
    bool ExistX = false;
    for (int i = 0; i<n; i++) {
        if ((s[i] == 'O') && (ExistX))
            cnt++;
        if (s[i] == 'X') {
            ExistX = true;
            ans *= (cnt+1LL);
            cnt = 0;
        }
    }
    if (!ExistX)
        return 0;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CHOCOLATE.INP", "r", stdin);
    freopen("CHOCOLATE.OUT", "w", stdout);
    cin >> s;
    cout << Solution();
    return 0;
}
