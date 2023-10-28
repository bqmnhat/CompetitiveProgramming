#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string s;

int main()
{
    cin >> n;
    cin.get();
    getline(cin, s, '\n');
    for (int i=1; i<n; i++)
        cout << s << '\n';
    cout << s;
    return 0;
}
