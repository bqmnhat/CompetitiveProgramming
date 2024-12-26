#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("LAPLAI.INP", "r", stdin);
    freopen("LAPLAI.OUT", "w", stdout);
    int t;
    cin>>t;
    int cases = 0;
    while(t--){
        cases++;

        int ans = 0;
        int a,b;
        cin>>a>>b;
        if(a<10 && b<10){
            cout<<"Case #"<<cases<<": "<<ans<<"\n";
        }

    }
    return 0;
}
