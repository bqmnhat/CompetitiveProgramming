#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[100001], la;

void ReadData() {
    int ai, PreAi = -1;
    la = 0;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if (ai != PreAi)
            la++;
        a[la]++;
        PreAi = ai;
    }
}

int Solution() {
    int ans = 0;
    for (int i=2; i<=la; i++)
        ans = max(ans, (min(a[i], a[i-1])*2));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
