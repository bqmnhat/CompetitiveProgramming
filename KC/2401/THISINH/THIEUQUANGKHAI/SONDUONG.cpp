#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("SONDUONG.INP", "r", stdin);
    freopen("SONDUONG.OUT", "w", stdout);
    int n,l,r;
    cin>>n>>l>>r;
    int ans = 0;
    int sizes = l+r;
    vector<int> ar(sizes,0);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        for(int j=a-l; j<b-l; j++){
            ar[j]++;

        }
    }
    for(int h=0; h<l+r; h++){
        if(ar[h]==2){
            ans++;
        }
    }
    cout<<ans;

    return 0;


}
