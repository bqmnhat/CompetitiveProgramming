#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int n, trace[MaxN+5];
queue <int> q;

vector <int> Digits(int x) {
    vector <int> ans;
    int tmp = x;
    while (x > 0) {
        ans.push_back(tmp - x%10);
        x = x/10;
    }
    return ans;
}

ll BFS() {
    ll ans = 0;
    q.push(n);
    trace[n] = -1;
    while (true) {
        int h = q.front();
        q.pop();
        if (h == 0)
            break;
        vector <int> v = Digits(h);
        for (int i=0; i<v.size(); i++) {
            int u = v[i];
            if (trace[u] == 0) {
                trace[u] = h;
                q.push(u);
            }
        }
    }
    int i = 0;
    while (i!=n) {
        i = trace[i];
        ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << BFS();
    return 0;
}
