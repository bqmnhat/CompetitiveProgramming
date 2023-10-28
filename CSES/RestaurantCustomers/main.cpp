#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int n;
vector<pii> t;

void ReadData() {
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        t.push_back(pii(a, 1));
        t.push_back(pii(b, -1));
    }
}

int Solution() {
    int ans = 0, tmp = 0;
    sort(t.begin(), t.end());
    for (int i=0; i<2*n; i++) {
        tmp += t[i].second;
        ans = max(ans, tmp);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
