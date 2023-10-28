#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int n;
pii a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
}

int Solution() {
    int ans = 1;
    sort(a+1, a+1+n);
    for (int i=1; i<=n; i++)
        if ((a[i].second < a[i-1].second))
            ans++;
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
