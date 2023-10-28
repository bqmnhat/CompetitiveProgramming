#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> a[16] = {{255, 255, 255}, {192, 192, 192}, {128, 128, 128}, {0, 0, 0}, {255, 0, 0},
                    {128, 0, 0}, {255, 255, 0}, {128, 128, 0}, {0, 255, 0}, {0, 128, 0}, {0, 255, 255},
                    {0, 128, 128}, {0, 0, 255}, {0, 0, 128}, {255, 0, 255}, {128, 0, 128} };
string s[16] = {"White", "Silver", "Gray", "Black", "Red", "Maroon", "Yellow", "Olive", "Lime", "Green", "Aqua", "Teal", "Blue", "Navy", "Fuchsia", "Purple"};
int c[3];

void SolveTestCase() {
    double MinVal = 1e9+7;
    int MinId;
    for (int i=0; i<16; i++) {
        double d = 0;
        for (int j=0; j<3; j++)
            d += (a[i][j] - c[j])*(a[i][j] - c[j]);
        d = sqrt(d);
        if (d < MinVal) {
            MinVal = d;
            MinId = i;
        }
    }
    cout << s[MinId] << '\n';
}

void Solve() {
    while ((cin >> c[0] >> c[1] >> c[2]) && ((c[0] != -1) || (c[1] != -1) || (c[2] != -1)))
        SolveTestCase();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
