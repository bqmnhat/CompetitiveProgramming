#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, Min = 1e9+1, Minid = 1e9, t;

void ReadData() {
    for (int i=1; i<=n; i++) {
        int ai;
        cin >> ai;
        if (Min > ai) {
            Min = ai;
            Minid = i;
        }
    }
}

void Solve(){
    for (int i=1; i<=t; i++) {
        Min = 1e9+1;
        cin >> n;
        ReadData();
        if (n%2 == 1)
            cout << "Mike";
        else if (Minid%2 == 0)
            cout << "Mike";
        else
            cout << "Joe";
        cout << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
