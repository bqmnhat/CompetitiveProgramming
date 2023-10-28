#include <bits/stdc++.h>
using namespace std;

struct diem
{
    double x, y;
};
struct duong
{
    double a, b ,c;
};
double khoangcach(diem p, duong l)
{
    return abs(l.a*p.x+l.b*p.y+l.c) / sqrt(l.a*l.a+l.b*l.b);
}
duong duongtoidiem(diem p1, diem p2)
{
    duong l;
    if(abs(p1.x-p2.x) < 1e-9)
    {
        l.a=1;
        l.b=0;
        l.c=-p1.x;
    }
    else
    {
        l.a=-(p1.y-p2.y)/(p1.x-p2.x);
        l.b=1;
        l.c=-(l.a*p1.x)-p1.y;
    }
    return l;
}
int main()
{
    freopen("DISTANCE.INP", "r", stdin);
    freopen("DISTANCE.OUT", "w", stdout);
    double ans = 1e18;
    int n;
    cin>>n;
    vector<diem> dagiac(n);
    for(int i=0; i<n; i++)
        cin>>dagiac[i].x>>dagiac[i].y;
    diem p;
    cin>>p.x>>p.y;
    for(int i=0; i<n; i++)
    {
        int j=(i+1)%n;
        duong l=duongtoidiem(dagiac[i], dagiac[j]);
        double d=khoangcach(p,l);
        ans=min(ans, d);
    }
    cout<<fixed<<setprecision(4)<<ans<<"\n";
    return 0;
}
