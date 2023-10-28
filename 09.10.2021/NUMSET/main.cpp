#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int Num[21], n;
map <string, int> m;

void Split() {
    for (int i=0; i<s.length(); i++) {
        Num[i] = s[i] - '0';
    }
    n = s.length();
}

bool IsConsecutive(int bin) {
    int cnt = 0, prebit = 1, tmp, i = 0;
    while (i<n) {
        tmp = (bin&1);
        if ((tmp == 0) && (prebit != 0))
            cnt++;
        if (cnt > 1)
            return false;
        prebit = tmp;
        bin = (bin >> 1);
        i++;
    }
    if ((tmp == 0) && (prebit != 0))
        cnt++;
    if (cnt > 1)
        return false;
    return true;
}

int Choices(int bin) {
    int ans = 0, cnt = 0;
    string s1 = "";
    bool exist = false;
    while (bin > 0) {
        int tmp = (bin&1);
        if (tmp == 1) {
            if (Num[cnt] != 0)
                exist = true;
            if (exist)
                s1 = s1 + char(Num[cnt] + '0');
            ans = (ans%3 + Num[cnt]%3)%3;
        }
        bin = (bin>>1);
        cnt++;
    }
    if (!exist)
        s1 = s1 + "0";
    if (m.find(s1) == m.end())
        m[s1]++;
    else
        ans = -1;
    return ans;
}

int Solution() {
    int x = (1<<n), ans = 0;
    for (int i=1; i<x; i++) {
        int tmp = -1;
        if (IsConsecutive(i))
            tmp = Choices(i);
        if (tmp == 0)
            ans++;
    }
    return ans;
}

int main()
{
    freopen("NUMSET.INP", "r", stdin);
    freopen("NUMSET.OUT", "w", stdout);
    cin >> s;
    Split();
    cout << Solution();
    return 0;
}
