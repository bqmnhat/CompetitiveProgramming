#include<bits/stdc++.h>
using namespace std;

struct tvh{
    double x;
    double y;
};;
int main()
{

    freopen("DISTANCE.INP","r",stdin);
    freopen("DISTANCE.OUT","w",stdout);
    tvh AB,PToLine;
    int n,x,y;
    cin>>n;
    cin>>x>>y;
    int Ax,Ay,Bx,By;
    cin>>Ax>>Ay;
    double TrueAns = 100000000;
    int firstPointx = Ax, firstPointy = Ay;
    for(int i=1;i<=n;i++)
    {
        if(i==n) Bx = firstPointx, By = firstPointy;
            else cin>>Bx>>By;
        AB.x = Bx - Ax ,AB.y = By - Ay,PToLine.x = x - Ax , PToLine.y = y - Ay;
        double T = AB.x * PToLine.y - PToLine.x * AB.y;
        double lengthAB = sqrt(AB.x * AB.x + AB.y * AB.y);
        double ans = abs(T) / lengthAB;
        TrueAns = min(TrueAns,ans);
        Ax = Bx;
        Ay = By;


    }

    cout<<setprecision(4)<<fixed<<TrueAns;
}

