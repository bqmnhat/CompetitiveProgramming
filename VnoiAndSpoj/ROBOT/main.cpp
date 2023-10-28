#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int Solution() {
    if (n&1)
        return -1;
    int UD = 0, RL = 0;
    for (int i=0; i<n; i++) {
        if (s[i] == 'L')
            RL++;
        else if (s[i] == 'R')
            RL--;
        else if (s[i] == 'U')
            UD++;
        else
            UD--;
    }
    UD = abs(UD);
    RL = abs(RL);
    int ans = (UD>>1) + (RL>>1);
    int rUD = UD%2, rRL = RL%2;
    if ((rUD) || (rRL))
        ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    cout << Solution();
    return 0;
}
