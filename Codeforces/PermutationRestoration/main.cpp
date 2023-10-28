#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
struct Element {
    int Min, Max, id;
} tmp[MaxN+1];
struct CmpEle {
    bool operator()(Element a, Element b) {
        if (a.Max == b.Max)
            return (a.Min > b.Min);
        return (a.Max > b.Max);
    }
};
int t, n, b[MaxN+1], a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> b[i];
}

bool CmpMin(Element a, Element b) {
    return (a.Min < b.Min);
}

void SolveTestCase() {
    priority_queue<Element, vector<Element>, CmpEle> pq;
    for (int i=1; i<=n; i++) {
        tmp[i].id = i;
        if (b[i] == 0) {
            tmp[i].Min = i+1;
            tmp[i].Max = n;
        }
        else {
            tmp[i].Min = i/(b[i] + 1) + 1;
            tmp[i].Max = i/b[i];
        }
    }
    sort(tmp+1, tmp+1+n, CmpMin);
    int j = 1;
    for (int i=1; i<=n; i++) {
        while ((j <= n) && (tmp[j].Min <= i)) {
            pq.push(tmp[j]);
            j++;
        }
        a[pq.top().id] = i;
        pq.pop();
    }
    for (int i=1; i<=n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
