#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int s[21], err[20][5], n, sid[5], tid[5];

void MakeS() {
    for  (int j=0; j<=9; j++) {
        s[j] = j;
    }
    for (int j=10; j<=19; j++) {
        s[j] = j+10;
    }
}

void ReadErr() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=4; j++)
            cin >> err[n][j];
    }
}

bool FoundX(int x, int val) {
    for (int i=1; i<=n; i++) {
        if (err[i][x] == val)
            return true;
    }
    return false;
}

bool CheckErr(int x, int cmd) {
    int st, ed;
    if (cmd == 0) {
        if (sid[x] < tid[x]) {
            st = tid[x];
            ed = sid[x] + 10;
        }
        else {
            st = tid[x];
            ed = sid[x];
        }
        for (int i=st; i<=ed; i++) {
            if (FoundX(x, s[i]))
                return true;
        }
        return false;
    }
    if (cmd == 1) {
        if (sid[x] > tid[x]) {
            st = sid[x];
            ed = tid[x] + 10;
        }
        else {
            st = sid[x];
            ed = tid[x];
        }
        for (int i=st; i<=ed; i++) {
            if (FoundX(x, s[i]))
                return true;
        }
        return false;
    }
}

int Solution() {
    int ans = -1, sum;
    for (int i=0; i<=15; i++) {
        int tmp = i;
        sum = 0;
        bool exist = false;
        for (int j=4; j>=1; j--) {
            int cmd = (tmp&1);
            if (cmd == 1) {
                if (sid[j] > tid[j])
                    sum += ((tid[j]+10) - sid[j]);
                else
                    sum += (tid[j] - sid[j]);
            }
            else {
                if (sid[j] < tid[j])
                    sum += ((sid[j]+10) - tid[j]);
                else
                    sum += (sid[j] - tid[j]);
            }
            if (!CheckErr(j, cmd)) {
                exist = true;
            }
            tmp = tmp>>1;
        }
        if ((exist) && ((sum < ans) || (ans == -1)))
            ans = sum;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> sid[1] >> sid[2] >> sid[3] >> sid[4] >> tid[1] >> tid[2] >> tid[3] >> tid[4] >> n;
    ReadErr();
    MakeS();
    cout << Solution();
    return 0;
}
