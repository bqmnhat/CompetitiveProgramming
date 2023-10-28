#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k, a[100001], sum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

int MaxLength() {
    int low = 1, high = sum/k, ans = 0, m, tmp;
    while (low<high) {
        m = (low + high)/2;
        tmp = 0;
        for (int i=1; i<=n; i++) {
            tmp = tmp + (a[i]/m);
        }
        if (tmp > k) {
            low = m+1;
        }
        else if (tmp < k) {
            high = m-1;
        }
        else if (m > ans)
            ans = m;
    }
    return m;
}

int main()
{
    freopen("WIRES.INP", "r", stdin);
    freopen("WIRES.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    cout << MaxLength();
    return 0;
}
