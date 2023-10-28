#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxFib 100000
using namespace std;
typedef long long ll;
int t, k;
ll fib[MaxFib+5], c[MaxN+1], SumC = 0;
priority_queue<ll> pq;

void ReadData() {
    while (!pq.empty())
        pq.pop();
    for (int i=1; i<=k; i++) {
        cin >> c[i];
        SumC += c[i];
        pq.push(c[i]);
    }
}

void MakeFib() {
    fib[0] = fib[1] = 1;
    for (int i=2; i<=100000; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        if (fib[i] > 1e11)
            break;
    }
}

bool Solution() {
    ll SumFib = 0;
    int m = -1;
    while (SumFib + fib[m+1] <= SumC) {
        m++;
        SumFib += fib[m];
    }
    if (SumFib != SumC)
        return false;
    ll CurCharVal;
    for (int i=m; i>=0; i--) {
        if (pq.empty())
            return false;
        ll tmpCharVal = pq.top();
        pq.pop();
        if ((i < m) && (CurCharVal != 0))
            pq.push(CurCharVal);
        CurCharVal = tmpCharVal;
        if (CurCharVal >= fib[i])
            CurCharVal -= fib[i];
        else
            return false;
    }
    return true;
}

void Solve() {
    MakeFib();
    for (int i=1; i<=t; i++) {
        SumC = 0;
        cin >> k;
        ReadData();
        if (Solution())
            cout << "Yes";
        else
            cout << "No";
        cout << "\n";
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
