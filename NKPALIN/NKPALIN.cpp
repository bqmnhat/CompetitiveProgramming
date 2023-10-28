#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s, ans1 ="", ans2="";
int a[127];

void Solve() {
    int i=0, j=s.length()-1;
    while (i<j) {
        a[s[i]]++;
        a[s[j]]++;
        if (a[s[i]] == 2) {
            ans1 = ans1 + s[i];
            ans2 = s[i] + ans2;
            a[s[i]] = 0;
        }
        if (a[s[j]] == 2) {
            ans1 = ans1 + s[j];
            ans2 = s[j] + ans2;
            a[s[j]] = 0;
        }
        i++;
        j--;
    }
    ans1 = ans1 + s[i];
    cout << ans1 << ans2;
}

int main()
{
    cin >> s;
    Solve();
    return 0;
}
