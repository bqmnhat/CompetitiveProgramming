#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[27],b[27];
string s1,s2;

int MaxDis() {
    int l1 = s1.length(), l2 = s2.length();
    int ans = 0;
    for (int i=0; i<l1; i++) {
        a[s1[i]-96]++;
    }
    for (int i=0; i<l2; i++) {
        b[s2[i]-96]++;
    }
    for (int i=1; i<=26; i++) {
        ans = ans + abs(a[i] - b[i]);
    }
    return ans;
}

int main()
{
    freopen("DISTANCE.INP", "r", stdin);
    freopen("DISTANCE.OUT", "w", stdout);
    cin >> s1 >> s2;
    cout << MaxDis();
    return 0;
}
