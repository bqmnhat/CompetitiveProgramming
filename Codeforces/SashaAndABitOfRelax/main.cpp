#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, a[300001];
ll tk[2][(1<<20)];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

ll Solution() {
    ll ans = 0;
    int Xor = 0;
    tk[0][0]++;
    for (int i=1; i<=n; i++) {
        Xor = (Xor^a[i]);
        ans += tk[i%2][Xor];
        tk[i%2][Xor]++;
    }
    return ans;
}

int main()
{
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
