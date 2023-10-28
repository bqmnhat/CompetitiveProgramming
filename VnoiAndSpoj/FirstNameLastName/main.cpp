#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
string s1, s2, s3;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> s1 >> s2 >> s3;
        if (s3 + s2 == s1)
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
    return 0;
}
