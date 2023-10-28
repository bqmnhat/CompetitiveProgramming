#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[10000001];

double Average() {
    ll sum = 0;
    double ans;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    ans = double(sum)/double(n);
    return ans;
}

void Solve() {
    double avg = Average();
    bool exist = false;
    for (int i=1; i<=n; i++) {
        if (double(a[i]) > avg) {
            if (!exist) {
                cout << i;
                exist = true;
            }
            else
                cout << " " << i;
        }
    }
    if (!exist)
        cout << "NOT FOUND";
}

int main()
{
    cin >> n;
    Solve();
    return 0;
}
