#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll steps[5];

void ReadData() {
    for (int i=1; i<=4; i++)
        cin >> steps[i];
}

ll Solution() {
    ll ans;
    sort(steps + 1, steps + 1 + 4);
    ans = steps[1]*steps[3];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TURTLE.INP", "r", stdin);
    freopen("TURTLE.OUT", "w", stdout);
    ReadData();
    cout << Solution();
    return 0;
}
