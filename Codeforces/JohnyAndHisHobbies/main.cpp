#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n, s[1025], tmp[1025];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }
}

bool CheckK(int k) {
    for (int i=1; i<=n; i++)
        tmp[i] = (s[i]^k);
    sort(tmp+1, tmp+1+n);
    for (int i=1; i<=n; i++)
        if (tmp[i] != s[i])
            return false;
    return true;
}

int FindK() {
    int m = (1 << 11)-1;
    for (int k=1; k<=m; k++) {
        if (CheckK(k))
            return k;
    }
    return -1;
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        sort(s+1, s+1+n);
        cout << FindK() << '\n';
    }
    return 0;
}
