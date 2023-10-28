#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Q;
long long a[600001], cnt = 0, topA = 0;

void Solve() {
    int cmd;
    long long x;
    for (int i=1; i<=Q; i++) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> x;
            topA++;
            cnt++;
            a[topA] = x;
        }
        else if (cmd == 2) {
            if (cnt != 0) {
                cout << a[topA - cnt + 1] << '\n';
                a[topA - cnt + 1] = 0;
                cnt--;
            }
            else
                cout << "-1" << '\n';
        }
        else if (cnt != 0){
            int start = topA - cnt + 1;
            sort(a+start, a+1+topA);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> Q;
    Solve();
    return 0;
}
