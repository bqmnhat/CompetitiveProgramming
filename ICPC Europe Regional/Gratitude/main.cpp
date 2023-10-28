#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Prac {
    string val;
    int Num, LastApp;
}a[100001];
int n,k, la = 0;
map<string, int> LastAppearance;
map<string, int> m;
string s;

void ReadData() {
    cin.ignore();
    for (int i=1; i<=3*n; i++) {
        getline(cin, s);
        LastAppearance[s] = i;
        m[s]++;
    }
}

bool Cmp(Prac a, Prac b) {
    if (a.Num == b.Num)
        return (a.LastApp > b.LastApp);
    return (a.Num > b.Num);
}

void Solve() {
    for (auto i : m) {
        Prac tmp;
        tmp.val = i.first;
        tmp.Num = i.second;
        tmp.LastApp = LastAppearance[i.first];
        la++;
        a[la] = tmp;
    }
    sort(a+1, a+1+la, Cmp);
    for (int i=1; i<=k; i++)
        cout << a[i].val << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    Solve();
    return 0;
}
