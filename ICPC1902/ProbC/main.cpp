#include <bits/stdc++.h>
typedef long long i64;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<i64> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n-1; i++) {
        i64 thisDie = arr[i] - i;
        if (thisDie < 0) {
            cout << "NO";
            return;
        }
        arr[i+1] += thisDie;
        arr[i] -= thisDie;
    }

    for (int i = 0; i < n-1; i++) {
        if (arr[i] >= arr[i+1]) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for (; t > 0; t--) {
        solve();
        cout << '\n';
    }
}
