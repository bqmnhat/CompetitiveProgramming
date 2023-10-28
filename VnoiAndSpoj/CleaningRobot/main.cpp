#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20
#define MaxDirt 10
#define MaxBit 3000
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int W, H, Rposx, Rposy, d[MaxN+1][MaxN+1], dpl = -1, di[4] = {-1, 0, 1, 0}, dj[4] = {0, 1, 0, -1};
ll FromR[MaxDirt+1], FromDirt[MaxDirt+1][MaxDirt+1], dp[MaxBit+1][MaxDirt+1];
string s[MaxN+1];
pii DirtPos[MaxDirt+1];
const ll inf = 1e9 + 5;

void ReadData() {
    for (int i=0; i<H; i++)
        cin >> s[i];
}

bool Check(int x, int y) {
    return ((x < H) && (x >= 0) && (y < W) && (y >= 0) && (s[x][y] != 'x'));
}

ll BFS(pii src, pii fin) {
    for (int i=0; i<=MaxN; i++)
        for (int j=0; j<=MaxN; j++)
            d[i][j] = -1;
    queue<pii> q;
    q.push(src);
    d[src.first][src.second] = 0;
    while (!q.empty()) {
        pii tmpu = q.front();
        q.pop();
        int ux = tmpu.first, uy = tmpu.second;
        if (tmpu == fin)
            return d[ux][uy];
        for (int i=0; i<4; i++) {
            int vx = ux + di[i], vy = uy + dj[i];
            if ((Check(vx, vy)) && (d[vx][vy] == -1)) {
                d[vx][vy] = d[ux][uy] + 1;
                q.push(pii(vx, vy));
            }
        }
    }
    return inf;
}

void IdentifyPositions() {
    dpl = -1;
    Rposx = Rposy = -1;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (s[i][j] == 'o') {
                Rposx = i;
                Rposy = j;
            }
            if (s[i][j] == '*') {
                dpl++;
                DirtPos[dpl] = pii(i, j);
            }
        }
    }
}

void MakeDists() {
    for (int i=0; i<=dpl; i++) {
        pii tmp = DirtPos[i];
        FromR[i] = BFS(pii(Rposx, Rposy), tmp);
        for (int j=0; j<=dpl; j++) {
            if (i == j)
                continue;
            FromDirt[i][j] = BFS(DirtPos[i], DirtPos[j]);
        }
    }
}

int CountBits(int x) {
    if (x == 0)
        return 0;
    return (CountBits(x >> 1) + (x&1));
}

ll Solution() {
    memset(dp, 0x200000f, sizeof(dp));
    IdentifyPositions();
    MakeDists();
    ll ans = inf;
    for (int i=1; i<(1 << (dpl+1)); i++) {
        for (int j=0; j<=dpl; j++) {
            if ((i>>j)&1) {
                if (CountBits(i) == 1) {
                    dp[i][j] = FromR[j];
                    continue;
                }
                else {
                    for (int k=0; k<=dpl; k++)
                        if ((i>>k)&1)
                            dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + FromDirt[k][j]);
                }
                if (i == ((1 << (dpl+1)) - 1))
                    ans = min(ans, dp[i][j]);
            }
        }
    }
    if (ans >= inf)
        ans = -1;
    return ans;
}

void Solve() {
    while ((cin >> W >> H) && ((W != 0) || (H != 0))) {
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
