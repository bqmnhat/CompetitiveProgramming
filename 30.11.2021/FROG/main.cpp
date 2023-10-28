#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans[1001], la = 0;
bool visited[1001];

void PrintAns(bool Reverse) {
    if (Reverse)
        for (int i=la; i>=1; i--)
            cout << ans[i]*(-1) << '\n';
    else
        for (int i=1; i<=la; i++)
            cout << ans[i] << '\n';
}

void PushToAns(int val) {
    la++;
    ans[la] = val;
}

void Solve() {
    bool Reverse;
    if (a > b) {
        Reverse = true;
        swap(a,b);
    }
    else
        Reverse = false;
    if (((b - a == 1) && (b != n) && (a != 1)) || (a == b)) {
        cout << "0";
        return;
    }
    int AtLeaf = a;
    if (a != 1) {
        while (AtLeaf - 2 >= 1) {
            AtLeaf -= 2;
            PushToAns(-2);
        }
        if (AtLeaf != 1) {
            AtLeaf--;
            PushToAns(-1);
        }
        else if (a != 1) {
            AtLeaf++;
            PushToAns(1);
        }
    }
    while (AtLeaf + 2 <= a+1) {
        AtLeaf += 2;
        PushToAns(2);
    }
    if ((a == 1) && (b == 2) && (n == 2))
        PushToAns(1);
    if ((b == a+1) && (b == n)) {
        PrintAns(Reverse);
        return;
    }
    while (AtLeaf+1 <= b-1) {
        AtLeaf++;
        PushToAns(1);
    }
    while (AtLeaf+2 <= n) {
        AtLeaf+=2;
        PushToAns(2);
    }
    if (AtLeaf != n) {
        AtLeaf++;
        PushToAns(1);
    }
    else if (b != n) {
        AtLeaf--;
        PushToAns(-1);
    }
    if (b == n) {
        PrintAns(Reverse);
        return;
    }
    while (AtLeaf - 2 >= b) {
        AtLeaf -= 2;
        PushToAns(-2);
    }
    PrintAns(Reverse);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FROG.INP", "r", stdin);
    freopen("FROG.OUT", "w", stdout);
    cin >> n >> a >> b;
    Solve();
    return 0;
}
