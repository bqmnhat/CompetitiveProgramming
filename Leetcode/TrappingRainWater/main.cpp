#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> stk;

int trap(vector<int>& height) {
    int n = height.size(), ans = 0;
    vector<int> nxtLarger(n+1, -1);
    vector<int> preLarger(n+1, n);

    //Find next Larger
    for (int i=0; i<n; i++) {
        while ((!stk.empty()) && (height[stk.back()] <= height[i])) {
            nxtLarger[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }

    //Find previous Larger
    stk.clear();
    for (int i=n-1; i>=0; i--) {
        while ((!stk.empty()) && (height[stk.back()] <= height[i])) {
            preLarger[stk.back()] = i;
            stk.pop_back();
        }
        stk.push_back(i);
    }

    int i = 0;
    while (i < n) {
        int nxt = nxtLarger[i], pre = preLarger[i];
        if (nxt != -1) {
            ans += height[i] * (nxt - i - 1);
            int j = i + 1;
            while (j < nxt) {
                ans -= height[j];
                height[j] = height[i];
                j++;
            }
            i = nxt;
        } else if (pre != n){
            ans += height[i] * (i - pre - 1);
            int j = i-1;
            while (j > pre) {
                ans -= height[j];
                height[j] = height[i];
                j--;
            }
            i++;
        } else
            i++;
    }
    return ans;
}

int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height);
    return 0;
}
