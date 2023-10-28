#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, a[100001];

void ReadData(int n, int a[100001]) {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

int MinCost() {
    sort(a+1,a+1+n, greater<int>());
    int ans = 0;
    for (int i = 1; i<=n; i++) {
        if (i % 3 != 0)
            ans = ans + a[i];
    }
    return ans;
}

int main()
{
    freopen("BOOK.INP", "r", stdin);
    freopen("BOOK.OUT", "w", stdout);
    cin >> n;
    ReadData(n,a);
    cout << MinCost();
    return 0;
}
