#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> Numbers;
ll X;

void DFS(ll Last, ll dif, int len) {
    if (len > 18)
        return;
    if ((((Last%10) + dif) > 9) || (((Last%10) + dif) < 0))
        return;
    ll Cur = Last*10 + ((Last%10) + dif);
    Numbers.push_back(Cur);
    DFS(Cur, dif, len+1);
}

void GenAllArith() {
    for (int i=1; i<=9; i++) {
        Numbers.push_back(i);
        DFS(i, 0, 2);
        for (int j=1; j<=9; j++) {
            DFS(i, j, 2);
            DFS(i, (-1LL)*j, 2);
        }
    }
    sort(Numbers.begin(), Numbers.end());
}

ll Solution() {
    int id = lower_bound(Numbers.begin(), Numbers.end(), X) - Numbers.begin();
    return Numbers[id];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    GenAllArith();
    cin >> X;
    cout << Solution();
    return 0;
}
