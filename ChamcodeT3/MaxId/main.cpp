#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int MaxId() {
    ll Max = 0, ans = 0, ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if (ai > Max) {
            Max = ai;
            ans = i;
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    cout << MaxId();
    return 0;
}
