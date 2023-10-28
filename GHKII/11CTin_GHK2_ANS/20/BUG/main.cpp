#include <bits/stdc++.h>
using namespace std;

int n, res=0, minstep = 100000, maxstep = -100000, pos[100000];
bool flag = true;
pair <int, int>bug[10000];
int main()
{
    freopen("BUG.INP", "r", stdin);
    freopen("BUG.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= 100000; i++){
        pos[i]=0;
    }
    for (int i = 1; i <=n; i++){
        cin >> bug[i].first>>bug[i].second;
        bug[i].first+=10000;
        bug[i].second+=10000;
        if (bug[i].first < minstep) minstep = bug[i].first;
        if (bug[i].second > maxstep) maxstep = bug[i].first;
        pos[bug[i].first+10000]++;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += bug[i].second;
    }
    if (sum%n!=0) flag = false;
    for (int i = 1; i <= n; i++){
        if (flag) res+=abs(sum/n-bug[i].second);
        else res+=abs(sum/n+1-bug[i].second);
    }
    for (int i = 1; i <= n; i++)
        if (pos [bug[i].first+10000]>1){
            if (maxstep==minstep) res+=i-1;
            else if (bug[i].first-minstep>maxstep) res += abs (maxstep-bug[i].first);
            else res += abs (minstep-bug[i].first);
    }
    cout << res;
    return 0;
}
