/*
5 2
0 1 4
1 2 1
0 7 3
0 20 10
1 4 5
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n,x, la[2];
pii a[2][2001];

void ReadData() {
    int t,h,w;
    for (int i=1; i<=n; i++) {
        cin >> t >> h >> w;
        la[t]++;
        a[t][la[t]] = {h, w};
    }
}

bool CmpPii(pii a, pii b) {
    if (a.first == b.first)
        return (a.second > b.second);
    return (a.first < b.first);
}

int Solution() {
    int ans = 0;
    sort(a[0]+1, a[0]+1+la[0], CmpPii);
    sort(a[1]+1, a[1]+1+la[1], CmpPii);
    int i,j,Type;
    i = j = 1;
    if (a[0][1].first < a[1][1].first)
        Type = 0;
    else
        Type = 1;
    while ((i <= la[0]) && (j <= la[1])) {
        if (Type == 0) {
            x = x - a[Type][i].first;
            if (x < 0)
                break;
            x += a[Type][i].second;
            i++;
        }
        else {
            x = x - a[Type][j].first;
            if (x < 0)
                break;
            x += a[Type][j].second;
            j++;
        }
        ans++;
        Type = 1 - Type;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ReadData();
    cout << Solution();
    return 0;
}
