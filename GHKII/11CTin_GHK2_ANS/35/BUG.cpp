#include <bits/stdc++.h>
using namespace std;
int maxy,miny;
double ans = INT_MAX;
vector<pair<int,int> > arr;
vector<int> listed;
int minX = INT_MAX;
void solve(){
    int n;
    cin>>n;
    miny = INT_MAX;
    int ncopy = n;
    while(n--){
        int tempa,tempb;
        cin>>tempa>>tempb;
        maxy = max(maxy,tempb);
        miny = min(miny,tempb);
        arr.push_back(make_pair(tempa,tempb));
        listed.push_back(tempa);
        minX = min(minX,tempa);
    }
    //cout<<miny<<" "<<maxy<<"\n";
    int ytarget = (maxy+miny)/2;
    int ans =0;
    for(int i=0;i<ncopy;++i){
        if(arr[i].second != ytarget){
            ans+= abs(arr[i].second - ytarget);
        }
    }
    //cout<<ans<<"\n";
    //cout<<minX<<"\n";
    int done = 0;
    sort(listed.begin(),listed.end());
    for(int i=0;i<ncopy;++i){
        //cout<<abs(i+minX)<<" ";
        if(listed[i]!=abs(i+minX-done)){
            ++done;
            ++ans;
        }
    }
    cout<<ans<<"\n";
}

int main(){
    freopen("BUG.INP","r",stdin);
    freopen("BUG.OUT","w",stdout);
    solve();
    return 0;
}
