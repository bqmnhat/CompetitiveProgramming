#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,RightInS[11],ans = 0;
string s[11];
bool IsRight[36];

void ReadData() {
    for (int i=0; i<m; i++)
        cin >> s[i] >> RightInS[i];
}

bool Check() {
    for (int i = 1; i<m; i++) {
        int CurCheckedRights = 0, tmp;
        for (int j=0; j<n; j++) {
            if (IsRight[j] == true)
                tmp = int(s[0][j] - '0');
            else
                tmp = 1 - int(s[0][j] - '0');
            if (tmp == int(s[i][j] - '0'))
                CurCheckedRights++;
        }
        if (CurCheckedRights != RightInS[i])
            return false;
    }
    return true;
}

void BackTracking(int i, int CurRights) {
    if (CurRights == RightInS[0]) {
        if (Check())
            ans++;
        return;
    }
    for (int j=i; j<n; j++) {
        IsRight[j] = true;
        BackTracking(j+1, CurRights+1);
        IsRight[j] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    BackTracking(0,0);
    cout << ans;
    return 0;
}
