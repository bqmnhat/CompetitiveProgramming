#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300
#define MaxVal 1000000
using namespace std;
int n, M, w[MaxN+1];
bool vis[MaxVal+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> w[i];
}

int Solution() {
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if ((w[i] <= M) && (!vis[w[i]])) {
            vis[w[i]] = true;
            cnt++;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j)
                continue;
            int sum = w[i] + w[j];
            if ((sum <= M) && (!vis[sum])) {
                vis[sum] = true;
                cnt++;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                if ((i == j) || (j == k) || (i == k))
                    continue;
                int sum = w[i] + w[j] + w[k];
                if ((sum <= M) && (!vis[sum])) {
                    vis[sum] = true;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> M;
    ReadData();
    cout << Solution();
    return 0;
}
