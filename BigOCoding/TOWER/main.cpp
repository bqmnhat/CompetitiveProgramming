#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int n, dp[101];
struct Block {
    int a, b, g, S;
} B[101];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> B[i].a >> B[i].b >> B[i].g;
        B[i].S = B[i].a * B[i].b;
    }
}

bool CmpBlock(Block a, Block b) {
    return (a.S > b.S);
}

bool IsFit(Block a, Block b) {
    return (((a.a <= b.a) && (a.b <= b.b)) || ((a.a <= b.b) && (a.b <= b.a)));
}

int Solution() {
    int ans = 0;
    sort(B+1, B+1+n, CmpBlock);
    for (int i=1; i<=n; i++)
        dp[i] = B[i].g;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<i; j++)
            if (IsFit(B[i], B[j]))
                dp[i] = max(dp[i], dp[j] + B[i].g);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
