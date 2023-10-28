#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x,y;
    void In()
    {
        cin>>x>>y;
    }
    void Debug(){
    cout<<"x: "<<x<<"\ny: "<<y;
    }
};

int main()
{
    freopen("BUG.INP","r",stdin);
    freopen("BUG.OUT","w",stdout);
    int N;
    cin>>N;
    Point Bug[N];
    int x[N];
    int MaxY=-INT_MAX;
    int MinY=INT_MAX;
    for (int i=0;i<N;i++)
    {
        Bug[i].In();
        x[i]=Bug[i].x;
        MaxY=max(MaxY,Bug[i].y);
        MinY=min(MinY,Bug[i].y);
    }
    int hangNgan=(MaxY+MinY)/2;
    int tmp;
    for (int i=0;i<N;i++)
    {
        for (int j=0;j<N;j++)
        {
            if (x[i]>x[j])
            {
                tmp=x[i];
                x[i]=x[j];
                x[j]=x[i];
            }
        }
    }
    tmp=x[0];
    int ans=abs(hangNgan-Bug[0].y);
    for (int i=1;i<N;i++)
    {
        ans+=abs(hangNgan-Bug[i].y);
        /*if (tmp==x[i])
        {
            ans++;
            x[i]++;
        }
        else if (x[i]-x[i-1]>1)
        {
            ans+=x[i]-tmp+1;
            x[i]-=x[i]-tmp+1;
        }
        tmp=x[i];*/
    }
    cout<<ans;
}
