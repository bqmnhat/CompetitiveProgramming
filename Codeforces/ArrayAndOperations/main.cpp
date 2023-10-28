#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,k;
long long a[101], ld, sum = 0;
struct Div {
    long long val, ReduceVal;
    int id1,id2;
} d[10001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

long long Solution() {
    sort(a+1, a+1+n);
    long long ans = 0;
    int cnt = 0;
    for (int i=n; i>=1; i--) {
        if (cnt == k)
            break;
        int x = a[i], y = a[i-k];
        sum = sum - x - y;
        ans += (min(x,y)/max(x,y));
        cnt++;
    }
    ans += sum;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        sum = 0;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
