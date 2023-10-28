#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef pair<int, int> pii;
int a[MaxN+1], n, r;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    int i=1, ans = 0;
    while (i <= n) {
        int NextAC = -1;
        for (int j=i; j<=i+r-1 && j<=n; j++) {
            if (a[j] == 1)
                NextAC = j;
        }
        if (NextAC == -1) {
            for (int j=i-1; j>=i-r+1 && j>=1; j--) {
                if (a[j] == 1) {
                    NextAC = j;
                    break;
                }
            }
            if (NextAC == -1)
                return -1;
        }
        ans++;
        i = NextAC + r;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r;
    ReadData();
    cout << Solution();
    return 0;
}
