#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
long long a[100001], sum;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

long long Cutable(long long l) {
    long long tmp = 0;
    for (int i=1; i<=n; i++)
        tmp = tmp + (a[i]/l);
    return tmp;
}

long long MaxLength() {
    long long low = 1, ans = 0, m, high = sum/k;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}
