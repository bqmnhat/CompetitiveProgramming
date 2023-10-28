#include <bits/stdc++.h>

using namespace std;
struct Point{
int x,y;
};
int main()
{
int t,x,y;
cin>>t;
Point centre ={0,0};

 while(t--){
    cin>>x>>y;
    centre.x+=x;
    centre.y+=y;
}
centre.x /=n;
centre.y /=n;
int result=0;
for(int i=0;i<n;i++){
    int dx=abs(centre.x-x[i]);
    int dy= abs(centre.y-y[i]);
    result+=max(dx,dy);
}
cout<<result;
return 0;
}

