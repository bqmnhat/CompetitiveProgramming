#include <bits/stdc++.h>
using namespace std;
int a,b;
double ans =INT_MAX;
void solve(){
    int n;
    cin>>n;
    cin>>a>>b;
    int abefore,bbefore;
    for(int i=0;i<n;++i){
        int atemp,btemp;
        cin>>atemp>>btemp;
        if(i!=0){
            int midA = (atemp-abefore)/2;
            int midB = (btemp-bbefore)/2;
            ans = min(ans,(double)sqrt((a-b)-(midA-midB)));
        }
        abefore =atemp;
        bbefore = btemp;
    }
    cout<<fixed<<setprecision(4)<<ans<<"\n";
}

int main(){
    freopen("DISTANCE.INP","r",stdin);
    freopen("DISTANCE.OUT","w",stdout);
    solve();
    return 0;
}
