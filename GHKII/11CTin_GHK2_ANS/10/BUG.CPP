#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
vector <pair<int,int>> points;
int main(){
    freopen("BUG.inp","r",stdin);
    freopen("BUG.out","w",stdout);
    int n,sum=0;
    cin>>n;
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        points.push_back(make_pair(x,y));
        sum+=y;
    }
    int ans1=0, ans2=0;
    int avg=trunc(sum/n);
    sort(points.begin(),points.end());
    for (int i=0;i<n-1;i++){
        ans1+=points[i+1].F-points[i].F-1;
    }
    for (int i=0;i<n;i++){
        ans2+=abs(points[i].S-avg);
    }
    cout<<ans1+ans2;

}
