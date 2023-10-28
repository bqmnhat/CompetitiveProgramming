#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n;
deque <int> dq;

void ReadData() {
    int ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        if ((ai <= dq.front()) || (dq.empty()))
            dq.push_front(ai);
        else
            dq.push_back(ai);
    }
}

void PrintAns() {
    while (!dq.empty()) {
        cout << dq.front() << " ";
        dq.pop_front();
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        PrintAns();
    }
    return 0;
}
