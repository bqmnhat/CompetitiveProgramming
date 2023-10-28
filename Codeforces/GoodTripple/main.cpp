#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
long long n, MaxR[300002];

long long Solution() {
    n = s.length();
    long long ans = 0;
    for (int i=0; i<=n; i++)
        MaxR[i] = n;
    for (int i=n-1; i>=0; i--) {
        MaxR[i] = MaxR[i+1];
        for (int k=1; i + 2*k < MaxR[i]; k++)
            if ((s[i] == s[i+k]) && (s[i+k] == s[i+2*k]))
                MaxR[i] = i + 2*k;
        ans += (n - MaxR[i]);
    }
    return ans;
}

int main()
{
    cin >> s;
    cout << Solution();
    return 0;
}
