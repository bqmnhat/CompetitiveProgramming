#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

int lengthOfLongestSubstring(string s) {
        int l = s.length(), ans = 0;
        vector<int> cnt[300];
        for (int i=0; i<300; i++) {
            cnt[i].assign(l+5, 1e9);
            cnt[i][0] = 0;
        }
        for (int i=1; i<=l; i++) {
            int tmpans = 1e9;
            for (int c=0; c<300; c++) {
                if (c == int(s[i-1]))
                    cnt[c][i] = cnt[c][i-1]+1;
                else
                    cnt[c][i] = cnt[c][i-1];
                if (cnt[c][i] == 0)
                    continue;
                int PrevId = upper_bound(cnt[c].begin(), cnt[c].end(), cnt[c][i]-2) - cnt[c].begin();
                if (PrevId >= cnt[c].size())
                    PrevId = cnt[c].size()-1;
                if (cnt[c][PrevId] != cnt[c][i]-1)
                    PrevId = i+1;
                else
                    PrevId++;
                tmpans = min(tmpans, (i-PrevId+1));
            }
            ans = max(ans, tmpans);
        }
        return ans;
    }

int main()
{
    /*ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);*/
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}
