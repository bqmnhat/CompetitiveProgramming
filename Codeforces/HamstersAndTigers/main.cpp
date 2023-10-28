#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int TigersToSwapfrom(int x, int l) {
    int ans = 0;
    for (int i=0; i<l; i++) {
        if (s[(x+i)%n] == 'T')
            ans++;
    }
    return ans;
}

int Solution() {
    int ans = 1e9, cntHamsters = 0;
    for (int i=0; i<n; i++)
        if (s[i] == 'H')
            cntHamsters++;
    for (int i=0; i<n; i++) {
        if (s[i] == 'H')
            ans = min(ans, TigersToSwapfrom(i,cntHamsters));
    }
    return ans;
}

int main()
{
    cin >> n >> s;
    cout << Solution();
    return 0;
}
