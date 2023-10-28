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

int Cutable(int l) {
    int tmp = 0;
    for (int i=1; i<=n; i++)
        tmp = tmp + (a[i]/l);
    return tmp;
}

int MaxLength() {
    int low = 1, high = sum/k, ans = 0, m, tmp;
    while (low<=high) {
        m = (low + high)/2;
        if (Cutable(m) >= k) {
            ans = m;
            low = m+1;
        }
        else
            high = m-1;
    }
    return ans;
}

void Solve() {
    while (cin >> n >> k) {
        sum = 0;
        ReadData();
        cout << MaxLength() << endl;
    }
}

int main()
{
    freopen("WIRES.INP", "r", stdin);
    freopen("WIRES.OUT", "w", stdout);
    Solve();
    return 0;
}
