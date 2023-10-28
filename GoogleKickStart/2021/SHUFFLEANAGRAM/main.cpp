#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int t, a[10001],n,gt[9];

void MakeA() {
    for (int i=1; i<=n; i++) {
        a[i] = s[i];
    }
}

bool Checked() {
    for (int i=1; i<=n; i++) {
        if (s[i] == a[i])
            return false;
    }
    return true;
}

void Solve() {

}

int main()
{
    cin >> s;
    n = s.length()-1;
    s = " " + s;
    MakeA();
    next_permutation(a+1, a+1+n);
    for (int i=1; i<=n; i++) {
        cout << char(a[i]);
    }
    return 0;
}
