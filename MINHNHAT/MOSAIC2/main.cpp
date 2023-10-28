#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
bool a[100][100];

int SBlank(int w, int h, int n){
    int x1,y1,x2,y2;
    int d = 0;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = min(x1,x2); i<= max(x1,x2); i++) {
        for (int j = min(y1,y2); j<= max(y1,y2); j++) {
            if (a[i][j] == false) {
                d = d + 1;
                a[i][j] = true;
            }
        }
    }
    return (w*h)-d;
}

int main()
{
    int w,h,n;
    freopen("MOSAIC.INP", "r", stdin);
    freopen("MOSAIC.OUT", "w", stdout);
    cin >> w >> h >> n;
    cout << SBlank(w,h,n,x,y);
    return 0;
}
