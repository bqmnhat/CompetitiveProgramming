#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

int Solution() {
    int ans = 0;
    for (int i = 1; i<=n; i++) {
        int tmp = 0, agree;
        for (int j=1; j<=3; j++) {
            cin >> agree;
            tmp += agree;
        }
        if (tmp >= 2)
            ans++;
    }
    return ans;
}

int main()
{
    cin >> n;
    cout << Solution();
    return 0;
}
