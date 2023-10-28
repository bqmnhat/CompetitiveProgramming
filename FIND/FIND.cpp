#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct student {
    string name;
    int d,m,y;
} st[101];
int n;

bool CmpStudent(student a, student b) {
    if (a.y == b.y) {
        if (a.m == b.m) {
            return (a.d > b.d);
        }
        else
            return (a.m > b.m);
    }
    else
        return (a.y > b.y);
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> st[i].name;
        cin >> st[i].d;
        cin >> st[i].m;
        cin >> st[i].y;
    }
}

void Solve() {
    sort(st+1, st+1+n, CmpStudent);
    cout << st[1].name << endl;
    cout << st[n].name;
}

int main()
{
    freopen("FIND.INP", "r", stdin);
    freopen("FIND.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
