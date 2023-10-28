#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MaxN 100000
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int t, n, k;
ll a[MaxN+5];
ordered_set os;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        os.insert(a[i]);
    }
}

void myerase(ll v){
    int Rank = os.order_of_key(v);
    ordered_set::iterator it = os.find_by_order(Rank);
    os.erase(it);
}

void printOrderedSet(ordered_set s){
    //Function to show the contents of the set
    for(auto it=s.begin(); it!=s.end(); it++){
        cout<<*it<<" ";
    }cout<<endl;
}

ll Solution() {
    ll ans = 0;
    os.insert(1e9);
    for (int i=1; i<n; i++) {
        ll tmpans = 0;
        if (a[i] <= a[i+1])
            tmpans = min(2*(*os.find_by_order(k)), a[i]);
        if (a[i+1] <= a[i])
            tmpans = min(2*(*os.find_by_order(k)), a[i+1]);
        if (k >= 1) {
            myerase(a[i+1]);
            tmpans = max(tmpans, min(2*(*os.find_by_order(k-1)), a[i]));
            os.insert(a[i+1]);
            myerase(a[i]);
            tmpans = max(tmpans, min(2*(*os.find_by_order(k-1)), a[i+1]));
            os.insert(a[i]);
        }
        if (k >= 2) {
            myerase(a[i]);
            myerase(a[i+1]);
            tmpans = max(tmpans, min(2*(*os.find_by_order(k-2)), 1LL*1000000000));
            os.insert(a[i]);
            os.insert(a[i+1]);
        }
        ans = max(ans, tmpans);
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        os.clear();
        cin >> n >> k;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie();
    cin >> t;
    Solve();
    return 0;
}
