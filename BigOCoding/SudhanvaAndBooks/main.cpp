#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int q;
stack<int> BookShelf;

void Solve() {
    for (int i=1; i<=q; i++) {
        int cmd;;
        cin >> cmd;
        if (cmd == 1) {
            int n;
            cin >> n;
            BookShelf.push(n);
        }
        else {
            if (!BookShelf.empty()) {
                cout << BookShelf.top() << '\n';
                BookShelf.pop();
            }
            else
                cout << "kuchbhi?" << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    Solve();
    return 0;
}
