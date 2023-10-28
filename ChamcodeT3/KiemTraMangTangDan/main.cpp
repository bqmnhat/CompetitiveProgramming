#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

bool IsInc() {
    long long ai, preai = -9000000000000000000;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if (ai <= preai)
            return false;
        preai = ai;
    }
    return true;
}

int main()
{
    cin >> n;
    if (!IsInc())
        cout << "FALSE";
    else
        cout << "TRUE";
    return 0;
}
