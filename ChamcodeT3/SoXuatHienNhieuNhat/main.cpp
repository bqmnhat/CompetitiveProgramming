#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, tk[1001];

void Solve() {
    int MaxId = -1, Max = 0, ai;
    for (int i = 1; i<=n; i++) {
        cin >> ai;
        tk[ai]++;
        if (tk[ai] > Max) {
            Max = tk[ai];
            MaxId = ai;
        }
    }
    cout << MaxId << " " << Max;
}

int main()
{
    cin >> n;
    Solve();
    return 0;
}
