#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
int t, n, a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        int bi;
        for (int j=1; j<=n; j++) {
            cin >> bi;
            string cmd;
            cin >> cmd;
            for (int k=0; k<bi; k++) {
                if (cmd[k] == 'D')
                    a[j] = (a[j] + 1)%10;
                else
                    a[j] = (a[j] - 1 + 10)%10;
            }
        }
        for (int i=1; i<=n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
