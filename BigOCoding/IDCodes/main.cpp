#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

void SolveTestCase() {
    int l = s.length();
    if (next_permutation(s.begin(), s.end()))
        cout << s;
    else
        cout << "No Successor";
    cout << '\n';
}

void Solve() {
    cin >> s;
    while (s != "#") {
        SolveTestCase();
        cin >> s;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
