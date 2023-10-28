#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a,b,c;

int Solution() {
    int ans = a + b*c;
    ans = max(ans, a*b + c);
    ans = max(ans, a*(b+c));
    ans = max(ans, (a+b)*c);
    ans = max(ans, a+b+c);
    ans = max(ans, a*b*c);
    return ans;
}

int main()
{
    cin >> a >> b >> c;
    cout << Solution();
    return 0;
}
