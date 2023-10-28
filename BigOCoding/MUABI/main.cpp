#include <iostream>
#include <bits/stdc++.h>
using namespace std;
pair<int, int> Marbles[1001];
int n,m;

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> Marbles[i].second >> Marbles[i].first;
}

int Solution() {
    sort(Marbles + 1, Marbles + 1 + m, greater<pair<int,int>>());
    int ans = 0;
    int i = 1;
    while ((i <= m) && (n - Marbles[i].second > 0)) {
        ans += (Marbles[i].second*Marbles[i].first);
        n = n - Marbles[i].second;
        i++;
    }
    if (n > 0)
        ans += n*Marbles[i].first;
    return ans;
}

int main()
{
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
