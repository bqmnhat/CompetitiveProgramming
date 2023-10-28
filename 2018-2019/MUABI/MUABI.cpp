#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
struct marble {
    int a,b; // a la so hop; b la so vien moi hop
}mar[1001];

void ReadData() {
    for (int i=1; i<=m; i++) {
        cin >> mar[i].a >> mar[i].b;
    }
}

bool CmpMarble(marble a, marble b) {
    return (a.b > b.b);
}

int Solution() {
    int ans = 0;
    sort(mar+1, mar+1+m, CmpMarble);
    int i=1;
    while ((n - mar[i].a >= 0) && (i <= m)) {
        ans = ans + (mar[i].a * mar[i].b);
        n = n - mar[i].a;
        i++;
    }
    if (n > 0) {
        ans = ans + (n * mar[i].b);
    }
    return ans;
}

int main()
{
    freopen("MUABI.INP", "r", stdin);
    freopen("MUABI.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
