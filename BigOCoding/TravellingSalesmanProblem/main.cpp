#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, C[16][16], MinCost = 1e9;
bool Start = false;
vector<bool> visit(16, false);

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> C[i][j];
        }
    }
}

bool check() {
    for (int i=1; i<=n; i++)
        if (!visit[i])
            return false;
    return true;
}

void BackTracking(int i, int sum) {
    if (sum >= MinCost)
        return;
    if (check()) {
        MinCost = min(MinCost, sum + C[i][1]);
        return;
    }
    for (int j = 1; j<=n; j++) {
        if ((!visit[j]) && (j != i)) {
            visit[j] = true;
            BackTracking(j, sum + C[i][j]);
            visit[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    visit[1] = true;
    BackTracking(1, 0);
    cout << MinCost;
    return 0;
}
