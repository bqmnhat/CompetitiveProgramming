#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[101], ans = 0;
bool dd[1001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if (!dd[a[i]]) {
            ans++;
            dd[a[i]] = true;
        }
    }
}

void Solve() {
    cout << ans << '\n';
    for (int i = 0; i<=1000; i++)
        dd[i] = false;
    bool exist = false;
    for (int i = 1; i<=n; i++) {
        int ans = 0;
        if (!dd[a[i]]) {
            dd[a[i]] = true;
            for (int j=1; j<=n; j++) {
                if (a[i] == a[j])
                    ans++;
            }
            if (!exist) {
                cout << a[i] << " " << ans;
                exist = true;
            }
            else
                cout << '\n' << a[i] << " " << ans;
        }
    }
}

int main()
{
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
