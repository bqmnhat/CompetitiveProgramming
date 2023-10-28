#include <iostream>
#include <bits/stdc++.h>
#define MaxN 52
using namespace std;
int n, Rank[MaxN+1], permu[4] = {1, 2, 3, 4}, SuitMap[257], HashVal[MaxN+1];
char Suit[MaxN+1];

void InitSuitMap() {
    SuitMap['s'] = 0;
    SuitMap['h'] = 1;
    SuitMap['d'] = 2;
    SuitMap['c'] = 3;
}

void ReadData() {
    string s;
    for (int i=1; i<=n; i++) {
        cin >> s;
        if ((s[0] >= '2') && (s[0] <= '9'))
            Rank[i] = s[0] - '2' + 1;
        else if (s[0] == 'T')
            Rank[i] = 9;
        else if (s[0] == 'J')
            Rank[i] = 10;
        else if (s[0] == 'Q')
            Rank[i] = 11;
        else if (s[0] == 'K')
            Rank[i] = 12;
        else
            Rank[i] = 13;
        Suit[i] = s[1];
    }
}

int LIS() {
    int dp[MaxN+1], ans = 0;
    for (int i=1; i<=n; i++)
        dp[i] = 1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<i; j++)
            if (HashVal[i] > HashVal[j])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int Solution() {
    int ans = 1e9;
    do {
        for (int i=0; i<16; i++) {
            for (int j=1; j<=n; j++) {
                HashVal[j] = permu[SuitMap[Suit[j]]]*100;
                if ((i & (1 << (SuitMap[Suit[j]]))) == 0)
                    HashVal[j] = HashVal[j] - Rank[j];
                else
                    HashVal[j] = HashVal[j] + Rank[j];
            }
            ans = min(ans, n - LIS());
        }
    } while (next_permutation(permu, permu + 4));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie();
    InitSuitMap();
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
