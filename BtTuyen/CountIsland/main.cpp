#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> MyPair;
int n, m, a[1001][1001], diri[9] = {0, -1, 0, 1, 0, -1, -1, 1, 1}, dirj[9] = {0, 0, 1, 0, -1, -1, 1, 1, -1};
bool visited[1001][1001];
stack<MyPair> stk;

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
}

bool Check(MyPair u) {
    return ((!visited[u.first][u.second]) && (a[u.first][u.second] == 1));
}

void DFS(int sti, int stj) {
    stk.push(make_pair(sti, stj));
    while (!stk.empty()) {
        MyPair u = stk.top();
        stk.pop();
        if (!visited[u.first][u.second])
            visited[u.first][u.second] = true;
        for (int i=1; i<=8; i++) {
            MyPair v;
            v.first = u.first+diri[i];
            v.second = u.second+dirj[i];
            if (Check(v)) {
                stk.push(v);
            }
        }
    }
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if ((!visited[i][j]) && (a[i][j] == 1)) {
                ans++;
                DFS(i,j);
            }
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
