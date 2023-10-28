#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct Point {int x,y;};
int main(){
    int n;
    cin >> n;
    Point center = {0, 0};
    for (int i = 0 ; i<=n;i++){
        int x,y;
    cin >> x >> y;
    center.x+=x;
    center.y+=y;
}
 center.x/=n;
 center.y/=n;
 int res = 0;
 for (int i=0; i<n;i++){
    int dx = abs(center.x - x);
    int dy = abs(center.y- y);
    res += max(dx,dy);
 }
    cout << res;
return 0;
}
