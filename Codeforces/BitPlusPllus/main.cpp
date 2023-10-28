#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, add = 0, sub = 0;

int Solution() {
    string cmd;
    for (int t=1; t<=n; t++) {
        cin >> cmd;
        int i = 0;
        while ((cmd[i] != '+') && (cmd[i] != '-'))
            i++;
        if (cmd[i] == '+')
            add++;
        else
            sub++;
    }
    int ans = add - sub;
    return ans;
}

int main()
{
    cin >> n;
    cout << Solution();
    return 0;
}
