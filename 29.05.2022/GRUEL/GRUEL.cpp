#include <iostream>
#include <bits/stdc++.h>
#define MaxN 10000
using namespace std;
typedef pair<int, int> pii;
pii t[2*MaxN+1];
int n, m, k;

void ReadData() {
    int ti, di, ai;
    for (int i=1; i<=k; i++) {
        cin >> ti >> di >> ai;
        ai++;
        int ed = ti + di;
        t[i] = pii(ti, ai);
        t[i+k] = pii(ed, -ai);
    }
}

bool CompareT(pii a, pii b) {
    return ((a.first < b.first) || ((a.first == b.first) && (a.second < b.second)));
}

void Solve() {
    sort(t+1, t+1+2*k, CompareT);
    int cntChao = 0, cntPho = 0;
    for (int i=1; i<=2*k; i++) {
        int Time = t[i].first, Meal = t[i].second;
        if (Meal < 0) {
            Meal = (-1)*Meal;
            if ((Meal == 1) && (cntChao > 0)) {
                n++;
                cntChao--;
            }
            else if (cntPho > 0) {
                n++;
                m++;
                cntPho--;
            }
        }
        else {
            if (Meal == 1) {
                if (n < 1)
                    cout << "No";
                else {
                    cout << "Yes";
                    cntChao++;
                    n--;
                }
            }
            else {
                if ((n < 1) || (m < 1))
                    cout << "No";
                else {
                    cout << "Yes";
                    cntPho++;
                    n--;
                    m--;
                }
            }
            cout << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GRUEL.INP", "r", stdin);
    freopen("GRUEL.OUT", "w", stdout);
    cin >> n >> m >> k;
    ReadData();
    Solve();
    return 0;
}
