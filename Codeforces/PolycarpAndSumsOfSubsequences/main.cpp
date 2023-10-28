#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
long long b[8];

void ReadData() {
    for (int i=1; i<=7; i++)
        cin >> b[i];
}

void Solve() {
    int NewB[8];
    sort(b+1, b+1+7);
    for (int i=1; i<=7; i++) {
        for (int j=1; j<=7; j++) {
            if (j == i)
                continue;
            for (int k = 1; k<=7; k++) {
                if ((k == j) || (k == i))
                    continue;
                NewB[1] = b[i];
                NewB[2] = b[j];
                NewB[3] = b[k];
                NewB[4] = b[i] + b[j];
                NewB[5] = b[i] + b[k];
                NewB[6] = b[j] + b[k];
                NewB[7] = b[i] + b[j] + b[k];
                bool Found = true;
                sort(NewB+1, NewB+1+7);
                for (int i=1; i<=7; i++) {
                    if (NewB[i] != b[i]) {
                        Found = false;
                        break;
                    }
                }
                if (Found) {
                    cout << b[i] << ' ' << b[j] << ' ' << b[k];
                    return;
                }
            }
        }
    }
}

void SolveAll() {
    for (int i=1; i<=t; i++) {
        ReadData();
        Solve();
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    SolveAll();
    return 0;
}
