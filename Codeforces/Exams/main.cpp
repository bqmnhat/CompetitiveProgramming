#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> Ipair;
int n;
Ipair x[5001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> x[i].first >> x[i].second;
}

bool CmpIPair(Ipair a, Ipair b) {
    if (a.first == b.first)
        return (a.second < b.second);
    return (a.first < b.first);
}

int Solution() {
    int ans = -1;
    sort(x+1, x+1+n, CmpIPair);
    for (int i=1; i<=n; i++) {
        if (ans <= x[i].second)
            ans = x[i].second;
        else
            ans = x[i].first;
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
