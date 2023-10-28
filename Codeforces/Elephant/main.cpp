#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int x;

int Solution() {
    int ans = x/5;
    if (x%5 != 0)
        ans++;
    return ans;
}

int main()
{
    cin >> x;
    cout << Solution();
    return 0;
}
