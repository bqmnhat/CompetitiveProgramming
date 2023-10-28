#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20
using namespace std;
int IniMask;
bool dp[(1 << MaxN)];
vector<vector<int>> Cons = {{0, 1, 2}, {3, 4, 5, 6}, {7, 8, 9, 10, 11}, {12, 13, 14, 15},
                            {16, 17, 18}, {2, 6, 11}, {1, 5, 10, 15}, {0, 4, 9, 14, 18},
                            {3, 8, 13, 17}, {7, 12, 16}, {0, 3, 7}, {1, 4, 8, 12},
                            {2, 5, 9, 13, 16}, {6, 10, 14, 17}, {11, 15, 18}};
vector<int> Moves;

void ReadData() {
    IniMask = 0;
    for (int i=0; i<19; i++) {
        char c;
        cin >> c;
        if (c == 'O')
            IniMask |= (1 << i);
    }
}

void MakeMoves() {
    for (int t = 0; t<Cons.size(); t++) {
        for (int i=0; i<Cons[t].size(); i++) {
            for (int j=i; j<Cons[t].size(); j++) {
                int mask = 0;
                for (int p=i; p<=j; p++)
                    mask |= (1 << Cons[t][p]);
                Moves.push_back(mask);
            }
        }
    }
}

void CalDp() {
    memset(dp, false, sizeof(dp));
    for (int mask = 1; mask < (1 << 19); mask++) {
        for (int MvMask: Moves) {
            if (mask&MvMask^MvMask)
                continue;
            if (dp[mask^MvMask] == false)
                dp[mask] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeMoves();
    CalDp();
    ReadData();
    if (dp[IniMask])
        cout << "Karlsson";
    else
        cout << "Lillebror";
    return 0;
}
