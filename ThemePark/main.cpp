#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, string> Ipair;
long long t, R, k, n;
queue<Ipair> g;
map<string, int> MapG;
long long Cost[10001];

void Init() {
    while (!g.empty())
        g.pop();
    MapG.clear();
}

void ReadData() {
    long long gi;
    for (int i = 1; i<=n; i++) {
        cin >> gi;
        int x = i;
        string id = "";
        while (x > 0) {
            int tmp = x%10;
            id = char(tmp + '0') + id;
            x = x/10;
        }
        g.push(make_pair(gi, id));
    }
}

long long Solution() {
    long long CycleLength = n, CycleStart = 1;
    string code = "";
    bool Exist = false;
    int i = 1;
    while (!Exist) {
        code = "";
        for (int i=1; i<=n; i++) {
            Ipair tmp = g.front();
            g.pop();
            code = code + " " + tmp.second;
            g.push(tmp);
        }
        if (MapG.find(code) != MapG.end()) {
            CycleStart = MapG[code];
            CycleLength = i - CycleStart;
            Exist = true;
        }
        else
            MapG[code] = i;
        Cost[i] = 0;
        queue<Ipair> tmpg;
        while ((Cost[i] + g.front().first <= k) && (!g.empty()) && (!Exist)) {
            Ipair tmp = g.front();
            g.pop();
            tmpg.push(tmp);
            Cost[i] += tmp.first;
        }
        Cost[i] += Cost[i-1];
        while ((!tmpg.empty()) && (!Exist)) {
            Ipair tmp = tmpg.front();
            tmpg.pop();
            g.push(tmp);
        }
        i++;
    }
    long long ans = Cost[CycleStart-1] + ((R - CycleStart + 1LL)/CycleLength)*(Cost[CycleStart + CycleLength - 1] - Cost[CycleStart - 1]);
    R = R - (CycleStart-1);
    R = R%CycleLength;
    for (long long i=1; i<=R; i++) {
        long long Benefit = 0;
        queue<Ipair> tmpg;
        while ((Benefit + g.front().first <= k) && (!g.empty())) {
            Ipair tmp = g.front();
            g.pop();
            tmpg.push(tmp);
            Benefit += tmp.first;
        }
        while (!tmpg.empty()) {
            Ipair tmp = tmpg.front();
            tmpg.pop();
            g.push(tmp);
        }
        ans += Benefit;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        Init();
        cin >> R >> k >> n;
        ReadData();
        cout << "Case #" << i << ": " << Solution() << '\n';
    }
}

int main()
{
    freopen("THEME.INP", "r", stdin);
    freopen("THEME.OUT", "w", stdout);
    cin >> t;
    Solve();
    return 0;
}
