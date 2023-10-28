#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, cntDistinct = 0;
bool vis[257];
ll AtMost[7];
string s;
const ll Mod = 998244353;

void CountDis() {
    for (int i=0; i<n; i++) {

    }
}

int CntAtMostK(string s, int k) {
    map<char,int> ma;
    int ans = 0;
    for(int i = 0 , j = 0; i < n; i++){
        char c = s[i];
        ma[c]++;
        while(map.size() > k){
            char c2 = s[j];
            ma[c2]--;
            if(ma[c2] <= 0)
                ma.erase(chj);
            j++;
        }
        ans += (i - j + 1);
    }
    return ans;
}

ll Solution() {
    for (int i=1; i<=k; i++)

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
