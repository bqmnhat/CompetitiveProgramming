#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s,s1;
int a[1001],k;

int NOfS1(int &k) {
    int l = s.length(), l1 = s1.length(), ans = 0;
    k = 1;
    for (int i=0; i<l; i++) {
        if (l - i >= l1) {
            if (s.substr(i,l1) == s1) {
                ans++;
                a[k] = i+1;
                k++;
            }
        }
    }
    k = k - 1;
    return ans;
}

int main()
{
    freopen("COUNTSTR.INP", "r", stdin);
    freopen("COUNTSTR.OUT", "w", stdout);
    cin >> s >> s1;
    cout << NOfS1(k) << endl;
    for (int i=1; i<=k; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
