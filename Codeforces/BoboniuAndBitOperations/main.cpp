#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200
using namespace std;
int n, m, a[MaxN+1], b[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int j=1; j<=m; j++)
        cin >> b[j];
}

bool Check(int x) {
    for (int i=1; i<=n; i++) {
        bool Found = false;
        for (int j=1; j<=m; j++) {
            if (((a[i]&b[j])|x) == x) {
                Found = true;
                break;
            }
        }
        if (!Found)
            return false;
    }
    return true;
}

int Solution() {
    int ans = (1<<9)-1;
    for (int i=8; i>=0; i--) {
        int tmp = (ans^(1<<i));
        if (Check(tmp))
            ans = tmp;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
