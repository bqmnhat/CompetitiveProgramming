#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, seat[9];
struct input{
    int a,b,c;
} Inp[21];

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> Inp[i].a >> Inp[i].b >> Inp[i].c;
}

int PosOfX(int x) {
    for (int i = 0; i<n; i++)
        if (seat[i] == x)
            return i;
}

int Solution() {
    for (int i=0; i<n; i++)
        seat[i] = i;
    int ans = 0;
    do {
        bool Found = true;
        for (int i=1; i<=m; i++) {
            int PosOfA = PosOfX(Inp[i].a), PosOfB = PosOfX(Inp[i].b);
            if ((Inp[i].c < 0) && (abs(PosOfA - PosOfB) < ((-1)*Inp[i].c))) {
                Found = false;
                break;
            }
            if ((Inp[i].c > 0) && (abs(PosOfA - PosOfB) > Inp[i].c)) {
                Found = false;
                break;
            }
        }
        if (Found)
            ans++;
    } while (next_permutation(seat, seat+n));
    return ans;
}

void Solve() {
    cin >> n >> m;
    while ((n != 0) || (m != 0)) {
        ReadData();
        cout << Solution() << '\n';
        cin >> n >> m;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
