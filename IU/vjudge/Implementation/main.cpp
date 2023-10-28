#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, pii> p4i;
int n, m, pref[MaxN+1][MaxN+1], a[MaxN+1][MaxN+1];
char Mode;
string s;
stack<p4i> q;

void Init() {
    for (int i=1; i<=MaxN; i++)
        for (int j=1; j<=MaxN; j++)
            pref[i][j] = a[i][j] = 0;
    while (!q.empty())
        q.pop();
}

void SplitData(string s, int a[MaxN+1][MaxN+1]) { //Just for input case B
    int l = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            a[i][j] = int(s[l] - '0');
            l++;
        }
    }
}

void GenPref(int a[MaxN+1][MaxN+1], int pref[MaxN+1][MaxN+1]) { // Just for input case B
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            pref[i][j] = pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1] + a[i][j];
}

int GetArea(int x1, int y1, int x2, int y2) { // Just for input case B
    return ((x2 - x1 + 1)*(y2 - y1 + 1));
}

int GetSum(int x1, int y1, int x2, int y2) { // Just for input case B
    return (pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1]);
}

vector<p4i> SplitIntoQuarters(int x1, int y1, int x2, int y2) {
    int RowSplit = (x1 + x2)/2, ColSplit = (y1 + y2)/2;
    vector<p4i> tmp;
    tmp.clear();
    if ((x2 - x1 + 1 > 1) && (y2 - y1 + 1 > 1)) {
        tmp.push_back(p4i(pii(RowSplit+1, ColSplit+1), pii(x2, y2)));
        tmp.push_back(p4i(pii(RowSplit+1, y1), pii(x2, ColSplit)));
        tmp.push_back(p4i(pii(x1, ColSplit+1), pii(RowSplit, y2)));
        tmp.push_back(p4i(pii(x1, y1), pii(RowSplit, ColSplit)));
    }
    else if  (x2 - x1 + 1 > 1) {
        tmp.push_back(p4i(pii(RowSplit+1, y1), pii(x2, y2)));
        tmp.push_back(p4i(pii(x1, y1), pii(RowSplit, y2)));
    }
    else if (y2 - y1 + 1 > 1) {
        tmp.push_back(p4i(pii(x1, ColSplit+1), pii(x2, y2)));
        tmp.push_back(p4i(pii(x1, y1), pii(x1, ColSplit)));
    }
    return tmp;
}

void FillRegion(int x1, int y1, int x2, int y2, int val) { //Just for input case D
    for (int i=x1; i<=x2; i++)
        for (int j=y1; j<=y2; j++)
            a[i][j] = val;
}

void QueryB() {
    cout << "D" << right << setw(4) << n << right << setw(4) << m << '\n';
    SplitData(s, a);
    GenPref(a, pref);
    q.push(p4i(pii(1,1), pii(n, m)));
    int cnt = 0;
    while (!q.empty()) {
        p4i SuperTmp = q.top();
        q.pop();
        pii tmpTL = SuperTmp.first, tmpBR = SuperTmp.second;
        int Sum = GetSum(tmpTL.first, tmpTL.second, tmpBR.first, tmpBR.second);
        int Area = GetArea(tmpTL.first, tmpTL.second, tmpBR.first, tmpBR.second);
        cnt++;
        if (cnt == 51) {
            cout << '\n';
            cnt = 1;
        }
        if ((Area == Sum) || (Sum == 0))
            cout << a[tmpTL.first][tmpTL.second];
        else {
            cout << "D";
            vector<p4i> tmp = SplitIntoQuarters(tmpTL.first, tmpTL.second, tmpBR.first, tmpBR.second);
            for (auto x: tmp)
                q.push(x);
        }
    }
}

void QueryD() {
    cout << "B" << right << setw(4) << n << right << setw(4) << m << '\n';
    q.push(p4i(pii(1,1), pii(n, m)));
    int l = s.length(), cnt = 0;
    for (int i=0; i<l; i++) {
        p4i SuperTmp = q.top();
        q.pop();
        pii tmpTL = SuperTmp.first, tmpBR = SuperTmp.second;
        if (s[i] == 'D') {
            vector<p4i> tmp = SplitIntoQuarters(tmpTL.first, tmpTL.second, tmpBR.first, tmpBR.second);
            for (auto x: tmp)
                q.push(x);
        }
        else if (s[i] == '1')
            FillRegion(tmpTL.first, tmpTL.second, tmpBR.first, tmpBR.second, 1);
        else
            FillRegion(tmpTL.first, tmpTL.second, tmpBR.first, tmpBR.second, 0);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cnt++;
            if (cnt == 51) {
                cout << '\n';
                cnt = 1;
            }
            cout << a[i][j];
        }
    }
}

void SolveTestCase() {
    Init();
    if (Mode == 'D')
        QueryD();
    else
        QueryB();
    cout << '\n';
}

void Solve() {
    string tmps;
    getline(cin, tmps);
    stringstream ss(tmps);
    ss >> Mode >> n >> m;
    while (Mode != '#') {
        s = "";
        getline(cin, tmps);
        while ((tmps[1] != ' ') && (tmps[0] != '#')) {
            s = s + tmps;
            getline(cin, tmps);
        }
        char NextMode;
        int NextN, NextM;
        if (tmps[1] == ' ') {
            stringstream ss(tmps);
            ss >> NextMode >> NextN >> NextM;
            SolveTestCase();
        }
        else {
            SolveTestCase();
            break;
        }
        Mode = NextMode;
        n = NextN;
        m = NextM;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("IMPLE.INP", "r", stdin);
    //freopen("IMPLE.OUT", "w", stdout);
    Solve();
    return 0;
}
