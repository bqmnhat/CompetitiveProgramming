#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, t, na, nb, lt = 0;
struct Train {
    int s, e, id;
}trains[201];
priority_queue<int, vector<int>, greater<int> > pq[2];

int Convert(string s) {
    return (((s[0] - '0')*10 + (s[1] - '0'))*60 + ((s[3] - '0')*10 + (s[4] - '0')));
}

void ReadData() {
    string TimeA, TimeB;
    for (int i=1; i<=na; i++) {
        cin >> TimeA >> TimeB;
        lt++;
        trains[lt].s = Convert(TimeA);
        trains[lt].e = Convert(TimeB);
        trains[lt].id = 0;
    }
    for (int i=1; i<=nb; i++) {
        cin >> TimeA >> TimeB;
        lt++;
        trains[lt].s = Convert(TimeA);
        trains[lt].e = Convert(TimeB);
        trains[lt].id = 1;
    }
}

bool CmpTrains(const Train& x, const Train& y) {
    return (x.s < y.s);
}

void SolveTestCases() {
    sort(trains+1, trains+1+lt, CmpTrains);
    int cnt[2] = {0, 0};
    for (int i=1; i<=lt; i++) {
        int d = trains[i].id;
        if ((!pq[d].empty()) && (pq[d].top() <= trains[i].s))
            pq[d].pop();
        else
            cnt[d]++;
        pq[1-d].push(trains[i].e + t);
    }
    cout << cnt[0] << ' ' << cnt[1] << '\n';
}

void Solve() {
    for (int i=1; i<=n; i++) {
        cin >> t >> na >> nb;
        lt = 0;
        while (!pq[0].empty())
            pq[0].pop();
        while (!pq[1].empty())
            pq[1].pop();
        ReadData();
        cout << "Case #" << i << ": ";
        SolveTestCases();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Solve();
    return 0;
}
