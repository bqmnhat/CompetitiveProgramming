#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,t;
string s;
struct Num {
    int val;
    char type;
}a[200001];

bool CmpNum(Num a, Num b) {
    if (a.val == b.val) {
        if (a.type == 'B')
            return true;
        else
            return false;
    }
    return (a.val < b.val);
}

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].val;
    cin >> s;
    for (int i=0; i<n; i++)
        a[i+1].type = s[i];
}

void Check() {
    sort(a+1, a+1+n,CmpNum);
    bool Can = true;
    for (int i=1; i<=n; i++) {
        if (((a[i].val < i) && (a[i].type == 'B')) || ((a[i].val > i) && (a[i].type == 'R'))) {
            Can = false;
            break;
        }
    }
    if (Can)
        cout << "YES";
    else
        cout << "NO";
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        Check();
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
