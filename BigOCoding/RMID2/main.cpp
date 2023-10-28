#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
priority_queue<int, vector<int>, greater<int>> Greater;
priority_queue<int> Smaller;

int MedQuerry() {
    while (Greater.size() < Smaller.size()) {
        Greater.push(Smaller.top());
        Smaller.pop();
    }
    while (Greater.size() > Smaller.size()) {
        Smaller.push(Greater.top());
        Greater.pop();
    }
    if (Greater.size() <= Smaller.size()) {
        int tmp = Smaller.top();
        Smaller.pop();
        return tmp;
    }
    else {
        int tmp = Greater.top();
        Greater.pop();
        return tmp;
    }
}

void SolveTestCase() {
    while (!Smaller.empty())
        Smaller.pop();
    while (!Greater.empty())
        Greater.pop();
    int Med = -1, cmd;
    while ((cin >> cmd) && (cmd != 0)) {
        if (cmd == -1) {
            Med = MedQuerry();
            cout << Med << '\n';
            continue;
        }
        if (Med == -1) {
            Med = cmd;
            Smaller.push(cmd);
            continue;
        }
        if (cmd <= Med)
            Smaller.push(cmd);
        else
            Greater.push(cmd);
    }
}

void Solve() {
    for (int i=1; i<=t; i++)
        SolveTestCase();
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
