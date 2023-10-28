#include <iostream>
#include <bits/stdc++.h>
#define MaxN 6
#define MaxTeams 64
using namespace std;
int n, Teams;
double dp[MaxN+1][MaxTeams+1], winRound[MaxN+1][MaxTeams+1], a[MaxTeams+1][MaxTeams+1];
vector<int> FightOpponent[MaxN+1][MaxTeams+1];

void ReadData() {
    for (int i=1; i<=Teams; i++) {
        for (int j=1; j<=Teams; j++) {
            cin >> a[i][j];
            a[i][j] = a[i][j]/100;
        }
    }
}

void WinRoundProb() {
    for (int i=1; i<=Teams; i++)
        winRound[0][i] = 1;
    for (int i=1; i<=n; i++) {
        int TeamsInAGroup = (1 << i), tmpi = 1;
        while (tmpi <= Teams) {
            for(int j=tmpi; j<=tmpi + TeamsInAGroup/2 - 1; j++)
                for (int t = tmpi + TeamsInAGroup/2; t<= tmpi + TeamsInAGroup - 1; t++)
                    FightOpponent[i][j].push_back(t);
            tmpi += TeamsInAGroup;
        }
        tmpi = (1 << i);
        while (tmpi <= Teams) {
            for(int j=tmpi; j>=tmpi - TeamsInAGroup/2 + 1; j--)
                for (int t = tmpi - TeamsInAGroup/2; t >= tmpi - TeamsInAGroup + 1; t--)
                    FightOpponent[i][j].push_back(t);
            tmpi += TeamsInAGroup;
        }
        for (int j=1; j<=Teams; j++) {
            double Tmp = 0;
            for (int x: FightOpponent[i][j])
                Tmp += (winRound[i-1][x]*double(a[j][x]));
            winRound[i][j] = winRound[i-1][j] * Tmp;
        }
    }
}

double Solution() {
    double Ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=Teams; j++) {
            double MaxScore = 0;
            for (int x: FightOpponent[i][j])
                MaxScore = max(MaxScore, dp[i-1][j] + dp[i-1][x] + winRound[i][j]*double((1 << (i-1))));
            dp[i][j] = MaxScore;
            if (i == n)
                Ans = max(Ans, dp[i][j]);
        }
    }
    return Ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Teams = (1 << n);
    ReadData();
    WinRoundProb();
    cout << fixed << setprecision(9) << Solution();
    return 0;
}
