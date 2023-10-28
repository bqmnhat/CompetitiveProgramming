#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[100];

int GCD(int a, int b) {
    int tmp = 0;
    while (b != 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

int MaxQ(int n, int a[]) {
    int ans = GCD(a[1], a[2]);
    for (int i = 2; i<=n; i++) {
        ans = GCD(ans,a[3]);
    }
    return ans;
}

void ReadData(int n, int a[]) {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

int main()
{
    int n;
    freopen("PT.INP", "r", stdin);
    freopen("PT.OUT", "w", stdout);
    cin >> n;
    ReadData(n,a);
    cout << MaxQ(n,a);
    return 0;
}
