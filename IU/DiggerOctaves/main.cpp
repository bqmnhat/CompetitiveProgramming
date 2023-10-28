#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, ans = 0, diri[5] = {0, -1, 0, 1, 0}, dirj[5] = {0, 0, 1, 0, -1};
string s[9];
map<string, int> check;
bool vis[9][9];
char a[9][9];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
}

void ConvertData() {
    int cnt = 40;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (s[i][j] == 'X') {
                cnt++;
                a[i][j] = char(cnt);
            }
        }
    }
}

bool Check(int x, int y) {
    return ((x >= 0) && (y >= 0) && (x < n) && (y < n) && (s[x][y] == 'X'));
}

bool InRepVal(const string& RepVal, char c) {
    int l = RepVal.length();
    for (int i=0; i<l; i++)
        if (RepVal[i] == c)
            return true;
    return false;
}

void DFS(int x, int y, int cnt, string RepVal) {
    if (cnt == 8) {
        sort(RepVal.begin(), RepVal.end());
        if (check.find(RepVal) == check.end()) {
            ans++;
            check[RepVal]++;
        }
        return;
    }
    for (int i=1; i<=4; i++) {
        int NewX = x + diri[i], NewY = y + dirj[i];
        string NewRepVal = RepVal + a[NewX][NewY];
        if ((Check(NewX, NewY)) && (!InRepVal(RepVal, a[NewX][NewY])))
            DFS(NewX, NewY, cnt+1, NewRepVal);
    }
}

int Solution() {
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (s[i][j] == '.')
                continue;
            string tmp = "";
            tmp = tmp + a[i][j];
            DFS(i, j, 1, tmp);
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        check.clear();
        ReadData();
        ConvertData();
        cout << Solution() << '\n';
        ans = 0;
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
