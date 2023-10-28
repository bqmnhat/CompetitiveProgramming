#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n;
ll k[MaxN+5];
set<int> Mark;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> k[i];
}

int Solution() {
    queue<int> q;
    int ans = 0;
    for (int i=1; i<=n; i++) {
        q.push(k[i]);
        if (Mark.count(k[i])) {
            while (q.front() != k[i]) {
                int tmp = q.front();
                q.pop();
                Mark.erase(Mark.find(tmp));
            }
            q.pop();
        }
        else
            Mark.insert(k[i]);
        ans = max(ans, (int)q.size());
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
