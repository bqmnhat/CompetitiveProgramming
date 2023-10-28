#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map <int, int> m;
int n, k, a[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    int i=1, j = k,cnt = 0, MaxAns, MaxDay;
    for (int x = i; x<=j; x++) {
        if (m.find(a[x]) == m.end())
            cnt++;
        m[a[x]]++;
    }
    MaxAns = cnt;
    MaxDay = 1;
    while (j < n) {
        j++;
        if (m.find(a[j]) == m.end())
            cnt++;
        else if (m[a[j]] == 0)
            cnt++;
        m[a[j]]++; m[a[i]]--;
        if (m[a[i]] == 0)
            cnt--;
        i++;
        if (cnt > MaxAns) {
            MaxAns = cnt;
            MaxDay = i;
        }
    }
    return MaxDay;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("EXCURS.INP", "r", stdin);
    freopen("EXCURS.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
