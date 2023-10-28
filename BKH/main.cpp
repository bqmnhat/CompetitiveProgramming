#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n, a[4] = {0,0,2,7}, la = 0;
queue <long long> q;
long long trace[500001], meth[500001];
string ans[3];

void Init() {
    for (int i=0; i<=500000; i++) {
        trace[i] = 0;
        meth[i] = 0;
    }
}

void BFS(long long st)  {
    q.push(st);
    trace[st] = -1;
    if (st == 2) meth[st] = 2;
    else meth[st] = 3;
    long long u, c = 0;
    bool exist = false;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (u == 0) {
            exist = true;
            break;
        }
        for (int i=1; i<=3; i++) {
            long long NewV =(u*10+ a[i])%n;
            if (trace[NewV] == 0) {
                q.push(NewV);
                trace[NewV] = u;
                meth[NewV] = i;
            }
        }
    }
    la++;
    if (exist == false) {
        la++;
        ans[la] = "-1";
    }
    else {
        while (u != -1) {
            ans[la] = char(a[meth[u]] + '0') + ans[la];
            u = trace[u];
        }
    }
}

void PrintAns() {
    if (ans[1].length() < ans[2].length())
        cout << ans[1];
    else if (ans[2].length() < ans[1].length())
        cout << ans[2];
    else if (ans[1] < ans[2])
        cout << ans[1];
    else
        cout << ans[2];
}

int main()
{
    freopen("BKH.INP", "r", stdin);
    freopen("BKH.OUT", "w", stdout);
    cin >> n;
    Init();
    BFS(2);
    Init();
    while (!q.empty())
        q.pop();
    BFS(7);
    PrintAns();
    return 0;
}
