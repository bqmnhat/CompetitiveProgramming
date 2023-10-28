#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a;
int x;
string ans;

void Change() {
    char c;
    while (a >= 1) {
        c = (a%x)+'0';
        ans = c + ans;
        a = a/x;
    }
    cout << ans;
}

int main()
{
    cin >> a >> x;
    Change();
    return 0;
}
