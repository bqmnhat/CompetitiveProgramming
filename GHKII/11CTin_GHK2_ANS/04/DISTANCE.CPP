#include <bits/stdc++.h>
using namespace std;
int x,y,a,b,c;
double Distance=1e9;
void distant(int x1,int y1,int x2, int y2){
    int dx=x2-x1, dy=y2-y1;
    a=-dy; b=dx; c=-a*x1+b*y1;
    double temp=(1.0*abs(a*x+b*y+c))/sqrt(a*a+b*b);
    if(Distance>temp) Distance=temp;
}

int main()
{
    freopen("DISTANCE.INP","r",stdin);
    freopen("DISTANCE.OUT","w",stdout);
    int n;
    pair<int,int> a[1001];
    cin>>n;
    cin>>x>>y;
    for(int i=0;i<n;++i){
        cin>>a[i].first>>a[i].second;
    }
    for(int i=0;i<n-1;++i){
        distant(a[i].first,a[i].second,a[i+1].first,a[i+1].second);
    }
    cout<<fixed<<setprecision(4)<<Distance;
}
