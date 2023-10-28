#include <bits/stdc++.h>
using namespace std;
#define INFINITY 1e9
#define maxN 10001



int n,xArr[maxN],yArr[maxN],x,y;
int solve(){
    long double ans = INFINITY;
    xArr[n+1]=xArr[1] ,yArr[n+1]=yArr[1];

    for (int i=2;i<=n+1;i++){
        long double x1 = xArr[i-1], y1=yArr[i-1], x2 = xArr[i], y2 = yArr[i];
        long double a1 = y2-y1,   b1 = x2-x1;
        long double c = a1*x1+b1*y1;
        c = -c;
        long double d = abs((a1*x+b1*y+c)/sqrt(a1*a1+b1*b1));
        ans = min(ans,d);
    }
    cout << fixed << setprecision(4) << ans;

}

int main(){
    freopen("DISTANCE.INP","r",stdin);
    freopen("DISTANCE.OUT","w",stdout);

    cin >> n;
    cin >> x >> y;

    for(int i=1;i<=n;i++)
        cin >> xArr[i] >> yArr[i];

    solve();
}

