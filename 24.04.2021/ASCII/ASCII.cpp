#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char a[101][101];
int h,w;

void ReadData() {
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            cin >> a[i][j];
        }
    }
}

int Area() {
    int area = 0;
    for (int i=1; i<=h; i++) {
        int mode = 0;
        for (int j=1; j<=w; j++) {
            if ((a[i][j] == '.') && (mode == 1)) {
                area += 2;
            }
            if ((a[i][j] == '/') || (a[i][j] == 92))  {
                area += 1;
                mode = 1-mode;
            }
        }
    }
    return area/2;
}

int main()
{
    freopen("ASCII.INP", "r", stdin);
    freopen("ASCII.OUT", "w", stdout);
    cin >> h >> w;
    ReadData();
    cout << Area();
    return 0;
}
