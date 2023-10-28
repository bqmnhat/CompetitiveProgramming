#include <bits/stdc++.h>
using namespace std;
#define Point pair<int, int>
#define F first
#define S second
double p2s(Point A, Point B, Point E){
    pair <int, int> AB;
    AB.F=B.F-A.F;
    AB.S=B.S-A.S;
    pair <int, int> BE;
    BE.F=E.F-B.F;
    BE.S=E.S-B.S;
    pair <int, int> AE;
    AE.F=E.F-A.F;
    AE.S=E.S-A.S;
    double AB_BE= AB.F*BE.F + AB.S*BE.S;
    double AB_AE= AB.F*AE.F + AB.S*AE.S;
    double disans=0;
    if (AB_BE>0){
        double y= E.S-B.S;
        double x= E.F-B.F;
        disans=sqrt(x*x+y*y);
    }
    else if (AB_AE<0){
        double y= E.S-A.S;
        double x= E.F-A.F;
        disans=sqrt(x*x+y*y);
    }
    else {
        double x1=AB.F;
        double y1=AB.S;
        double x2=AE.F;
        double y2=AE.S;
        double div=sqrt(x1*x1+y1*y1);
        disans=abs(x1*y2-y1*x2)/div;
    }
    return disans;
}

int main(){
    freopen("DISTANCE.inp","r",stdin);
    freopen("DISTANCE.out","w",stdout);
    int n,x0,y0,x[1005],y[1005];
    double ans =INT_MAX;
    cin>>n>>x0>>y0;
    Point E=make_pair(x0,y0);
    for (int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for (int i=0;i<n-1;i++){
        for (int j=i+1;j<n;j++){
            Point A= make_pair(x[i],y[i]);
            Point B= make_pair(x[j],y[j]);
            ans=min(ans,p2s(A,B,E));
        }
    }
    cout<<fixed<<set_precision(4)<<ans;
}
