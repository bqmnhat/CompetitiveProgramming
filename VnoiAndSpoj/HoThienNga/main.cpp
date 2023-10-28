#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1505
using namespace std;
typedef pair<int, int> pii;
int r, c, lx1, ly1, lx2, ly2, diri[4] = {-1, 0, 1, 0}, dirj[4] = {0, 1, 0, -1};
bool vis[MaxN][MaxN], InNextStep[MaxN][MaxN];
string s[MaxN];
queue<pii> q, q2;
struct DSU {
    int par[MaxN*MaxN];
    void MakeAllSet(int r, int c) {
        for (int i=0; i<r; i++)
            for (int j=0; j<c; j++)
                par[i*c + j] = i*c + j;
    }
    int FindSet(int repval) {
        if (par[repval] == repval)
            return repval;
        return (par[repval] = FindSet(par[repval]));
    }
    void UnionSet(int vala, int valb) {
        vala = FindSet(vala);
        valb = FindSet(valb);
        if (vala != valb)
            par[valb] = vala;
    }
}dsu;
const int inf = 1e9 + 7;

void ReadData() {
    for (int i=0; i<r; i++)
        cin >> s[i];
}

void InitStep1() {
    dsu.MakeAllSet(r, c);
    lx1 = ly1 = lx2 = ly2 = -1;
    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (s[i][j] != 'X') {
                if (s[i][j] == 'L') {
                    if (lx1 == -1) {
                        lx1 = i;
                        ly1 = j;
                    }
                    else {
                        lx2 = i;
                        ly2 = j;
                    }
                }
                q.push(pii(i, j));
                vis[i][j] = true;
            }
        }
    }
}

bool Check(int x, int y) {
    return ((x >= 0) && (x < r) && (y >= 0) && (y < c));
}

void Step1() {
    InitStep1();
    while (!q.empty()) {
        pii tmp = q.front();
        q.pop();
        int ux = tmp.first, uy = tmp.second;
        for (int i=0; i<4; i++) {
            int vx = ux + diri[i], vy = uy + dirj[i];
            if ((Check(vx, vy)) && (s[vx][vy] != 'X')) {
                dsu.UnionSet(ux*c + uy, vx*c + vy);
                if (!vis[vx][vy]) {
                    vis[vx][vy] = true;
                    q.push(pii(vx, vy));
                }
            }
            else if ((Check(vx, vy)) && (!InNextStep[ux][uy])) {
                vis[ux][uy] = InNextStep[ux][uy] = true;
                q2.push(pii(ux, uy));
            }
        }
    }
}

int FinalStep() {
    int ans = 0, sq2;
    while (dsu.FindSet(lx1*c + ly1) != dsu.FindSet(lx2*c + ly2)) {
        ans++;
        sq2 = q2.size();
        while (sq2) {
            sq2--;
            pii tmp = q2.front();
            q2.pop();
            int ux = tmp.first, uy = tmp.second;
            for (int i=0; i<4; i++) {
                int vx = ux + diri[i], vy = uy + dirj[i];
                if (Check(vx, vy)) {
                    dsu.UnionSet(ux*c+uy, vx*c + vy);
                    if (!vis[vx][vy]) {
                        vis[vx][vy] = true;
                        q2.push(pii(vx, vy));
                        for (int j=0; j<4; j++) {
                            int kx = vx + diri[j], ky = vy + dirj[j];
                            if (vis[kx][ky])
                                dsu.UnionSet(vx*c+vy, kx*c + ky);
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    ReadData();
    Step1();
    cout << FinalStep();
    return 0;
}
