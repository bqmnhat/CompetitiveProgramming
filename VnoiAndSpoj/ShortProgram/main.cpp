#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
int n, bits[15], CmdEffect[10][10];

void Init() {
    CmdEffect[0][0] = CmdEffect[1][1] = 0;
    CmdEffect[0][1] = CmdEffect[1][0] = 1;
    CmdEffect[0][2] = CmdEffect[1][2] = CmdEffect[2][0] = CmdEffect[2][2] = CmdEffect[3][1] = CmdEffect[3][2] = 2;
    CmdEffect[0][3] = CmdEffect[1][3] = CmdEffect[2][1] = CmdEffect[2][3] = CmdEffect[3][0] = CmdEffect[3][3] = 3;
}

void Solve() {
    for (int i=1; i<=n; i++) {
        char cmd;
        int xi;
        cin >> cmd >> xi;
        for (int i=0; i<10; i++) {
            int CmdCode, CurBitOfXi = (xi&(1 << i));
            if (cmd == '&') {
                if (CurBitOfXi)
                    CmdCode = 0;
                else
                    CmdCode = 2;
            }
            else if (cmd == '|') {
                if (CurBitOfXi)
                    CmdCode = 3;
                else
                    CmdCode = 0;
            }
            else {
                if (CurBitOfXi)
                    CmdCode = 1;
                else
                    CmdCode = 0;
            }
            bits[i] = CmdEffect[bits[i]][CmdCode];
        }
    }
    int XORVal = 0, ORVal = 0, ANDVal = (1 << 10) - 1;
    for (int i=0; i<10; i++) {
        if (bits[i] == 1)
            XORVal ^= (1 << i);
        else if (bits[i] == 2)
            ANDVal &= ~(1 << i);
        else if (bits[i] == 3)
            ORVal |= (1 << i);
    }
    cout << 3 << '\n';
    cout << "^ " << XORVal << '\n' << "& " << ANDVal << '\n' << "| " << ORVal << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Init();
    cin >> n;
    Solve();
    return 0;
}
