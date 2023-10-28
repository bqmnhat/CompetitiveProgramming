#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int room[200001], guest[200001], m, n, k;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> guest[i];
    }
    for (int i=1; i<=m; i++) {
        cin >> room[i];
    }
}

int MaxAvailable() {
    int ans = 0, i=1, j=1;
    sort(room + 1, room + 1 + m);
    sort(guest + 1, guest + 1 + n);
    while ((i<=m) && (j<=n)) {
        if ((room[i] <= guest[j] + k) && (room[i] >= guest[j] - k)) {
            ans++;
            j++;
            i++;
        }
        else if (room[i] < guest[j] - k){
            i++;
        }
        else if (room[i] > guest[j]+k) {
            j++;
        }
    }
    return ans;
}

int main()
{
    freopen("APPARTMENTS.INP", "r", stdin);
    freopen("APPARTMENTS.OUT", "w", stdout);
    cin >> n >> m >> k;
    ReadData();
    cout << MaxAvailable();
    return 0;
}

