#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,k,a[100001];

void ReadData(int n, int a[100001]) {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

long long MaxVal() {
    long long ans = a[1];
    sort(a+2,a+n+1,greater<int>());
    int d = 0;
    for (int i = 2; i<=n; i++) {
        if (d<k) {
            ans = ans + a[i];
            d = d + 1;
        }
        else
            ans = ans - a[i];
    }
    return ans;
}

int main()
{
    freopen("EXPRESS.INP", "r", stdin);
    freopen("EXPRESS.OUT", "w", stdout);
    cin >> n >> k;
    ReadData(n,a);
    cout << MaxVal();
    return 0;
}
