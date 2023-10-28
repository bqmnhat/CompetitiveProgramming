#include <bits/stdc++.h>

using namespace std;
int x,y,a,b,c,n;
pair<int,int> p[10007];
double res = 1e9;

void pt (int x1,int y1,int x2,int y2)
{
    int cpX,cpY;
    cpX = x2-x1;
    cpY = y2-y1;
    a = -(cpX);
    b = cpX;
    c = -(a*x1)+(b*x2);
    double tam = (1.0*abs(a*x+b*y+c))/sqrt(a*a+b*b);
    if (res > tam) res = tam;
}

int main()
{
    freopen("DISTANCE.INP","r",stdin);
    freopen("DISTANCE.OUT","w",stdout);
    cin >> n;
    cin >> x >> y;
    for (int i = 1;i<=n;i++)
        cin >> p[i].first>> p[i].second;
    for (int i = 1;i<=n-1;i++)
    {
        pt(p[i].first,p[i].second,p[i+1].first,p[i+1].second);
    }
    cout << fixed << setprecision(4) << res;
    return 0;
}
