#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
struct SuffTreeNode {
    int next[26];
    int len;
    int sufflink;
};
int t, n, m;
string s1, s2, s, Concat;
// For suffixSort and LCP
int p1[MaxN + 5], p2[MaxN + 5];
int iSA[MaxN + 5], SA[MaxN + 5];
int len, num, suff, fd[MaxN + 5], bd[MaxN + 5];
int cnt[MaxN + 5], next_gen[MaxN + 5], lcp[MaxN + 5], LCP[MaxN + 5][22], SuffixArrayS1[MaxN + 5], SuffixArrayS2[MaxN + 5];
bool bh[MaxN + 5], b2h[MaxN + 5];

SuffTreeNode SuffTree[MaxN + 5];

// Suffix Tree

void ResetSuffTree() {
    for(int i=0; i<=num; i++) {
        SuffTree[i].len = 0;
        SuffTree[i].sufflink = 0;
        memset(SuffTree[i].next, 0, sizeof(SuffTree[i].next));
    }
}

void InitSuffTree() {
    num = 2; suff = 2;
    SuffTree[1].len = -1;
    SuffTree[1].sufflink = 1;
    SuffTree[2].len = 0;
    SuffTree[2].sufflink = 1;
}

bool addLetter(int pos) {
    int cur = suff, curlen = 0;
    int c = s[pos] - 'a';
    while (true) {
        curlen = SuffTree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
            break;
        cur = SuffTree[cur].sufflink;
    }
    if (SuffTree[cur].next[c]) {
        suff = SuffTree[cur].next[c];
        return false;
    }
    num++;
    suff = num;
    SuffTree[num].len = SuffTree[cur].len + 2;
    SuffTree[cur].next[c] = num;
    if (SuffTree[num].len == 1) {
        SuffTree[num].sufflink = 2;
        return true;
    }
    while (true) {
        cur = SuffTree[cur].sufflink;
        curlen = SuffTree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos]) {
            SuffTree[num].sufflink = SuffTree[cur].next[c];
            break;
        }
    }
    return true;
}

// Suffix Sort and LCP

bool Smaller(int a, int b){
    return Concat[a] < Concat[b];
}

void SuffixRadixSort(int n) {
    for (int i=0; i<n;++i){
        SA[i] = i;
    }
    sort(SA, SA + n, Smaller);
    for (int i=0; i<n;++i){
        bh[i] = ((i == 0) || (Concat[SA[i]] != Concat[SA[i-1]]));
        b2h[i] = false;
    }
    for (int h = 1; h < n; h <<= 1){
        int buckets = 0;
        for (int i=0, j; i < n; i = j){
            j = i + 1;
            while ((j < n) && (!bh[j]))
                j++;
            next_gen[i] = j;
            buckets++;
        }
        if (buckets == n) break;
        for (int i = 0; i < n; i = next_gen[i]){
            cnt[i] = 0;
            for (int j = i; j < next_gen[i];++j){
                iSA[SA[j]] = i;
            }
        }
        cnt[iSA[n - h]]++;
        b2h[iSA[n - h]] = true;
        for (int i = 0; i < n; i = next_gen[i]){
            for (int j = i; j < next_gen[i];++j){
                int s = SA[j] - h;
                if (s >= 0){
                    int head = iSA[s];
                    iSA[s] = head + cnt[head]++;
                    b2h[iSA[s]] = true;
                }
            }

            for (int j = i; j < next_gen[i];++j){
                int s = SA[j] - h;
                if ((s >= 0) && (b2h[iSA[s]])) {
                    for (int k = iSA[s]+1; (!bh[k]) && (b2h[k]); k++)
                        b2h[k] = false;
                }
            }
        }

        for (int i=0; i<n;++i){
            SA[iSA[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    for (int i=0; i<n;++i){
        iSA[SA[i]] = i;
    }
}

void InitLCP(int len) {
    for (int i=0; i<len;++i)
        iSA[SA[i]] = i;
    lcp[0] = 0;
    for (int i=0, h=0; i<len;++i)
    {
        if (iSA[i] > 0)
        {
            int j = SA[iSA[i]-1];
            while ((i + h < len) && (j + h < len) && (Concat[i+h] == Concat[j+h]))
                h++;
            lcp[iSA[i]] = h;
            if (h > 0)
                h--;
        }
    }
}

void ConstructLCP(int len) {
    InitLCP(len);
    for(int i = 0;i<len;++i)
        LCP[i][0] = lcp[i];
    for(int j = 1;(1<<j)<=len;++j){
        for(int i = 0;i+(1<<j)-1<len;++i){
            if(LCP[i][j-1]<=LCP[i+ (1<<(j-1))][j-1])
                LCP[i][j] = LCP[i][j-1];
            else
                LCP[i][j] = LCP[i+(1<<(j-1))][j-1];
        }
    }
}

int GetLCP(int x, int y, int len) {
    if(x == y)
        return (len-SA[x]);
    if(x > y)
        swap(x,y);
    int log = 0;
    while((1<<log) <= (y-x))
        log++;
    log--;
    int ans = min(LCP[x+1][log],LCP[y-(1<<log)+1][log]);
    return ans;
}

// Other functions and procedures

void Init(int n) {
    for(int i = 0; i<=n; i++) {
        iSA[i] = 0;
        SA[i] = 0;
        cnt[i] = 0;
        next_gen[i] = 0;
        lcp[i] = 0;
        bh[i] = 0;
        b2h[i] = 0;
        int j;
        for(int j = 0; j<=20; j++)
            LCP[i][j] = 0;
    }
}

void SolveTestCase() {
    n = s1.length();
    m = s2.length();

    Init(n);
    Concat = s1;
    SuffixRadixSort(n);
    for(int i=0; i<n; i++)
        SuffixArrayS1[i] = iSA[i];

    Init(m);
    Concat = s2;
    reverse(Concat.begin(), Concat.end());

    SuffixRadixSort(m);
    for(int i=0; i<m; i++)
        SuffixArrayS2[m-1-i] = iSA[i];

    s = s1;
    reverse(s.begin(), s.end());
    InitSuffTree();
    for(int i = 0; i < n; i++) {
        addLetter(i);
        p1[n-1-i] = SuffTree[suff].len;
    }
    p1[n] = 0;

    s = s2;
    ResetSuffTree();
    InitSuffTree();
    for(int i=0; i<m; i++) {
        addLetter(i);
        p2[i] = SuffTree[suff].len;
    }

    int len = n + m + 1;
    Init(len);
    Concat = s1;
    reverse(Concat.begin(), Concat.end());
    Concat = Concat + '$' + s2;

    SuffixRadixSort(len);
    ConstructLCP(len);

    int pos1, pos2;
    pos1 = pos2 = -1;
    for(int i = 0; i<len; i++) {
        if(SA[i] > n) {
            bd[SA[i]] = pos1;
            pos2 = SA[i];
        } else if(SA[i] < n){
            bd[SA[i]] = pos2;
            pos1 = SA[i];
        }
    }

    pos1 = pos2 = -1;
    for(int i = len - 1; i>=0; i--) {
        if(SA[i] > n) {
            fd[SA[i]] = pos1;
            pos2 = SA[i];
        } else if(SA[i] < n) {
            fd[SA[i]] = pos2;
            pos1 = SA[i];
        }
    }

    int l, r, curlen = 0;
    l = r = -1;
    curlen = 0;
    for(int i=0; i<n; i++) {
        int tmp = 0;
        if(fd[n-1-i] != -1)
            tmp = max(tmp, GetLCP(iSA[n-1-i], iSA[fd[n-1-i]], len));
        if(bd[n-1-i] != -1)
            tmp = max(tmp, GetLCP(iSA[n-1-i], iSA[bd[n-1-i]], len));
        if((tmp > 0) && (curlen < tmp*2 + p1[i+1])) {
            l = i-tmp+1;
            r = i + p1[i+1];
            curlen = tmp*2 + p1[i+1];
        } else if((tmp > 0) && (curlen == tmp*2 + p1[i+1])) {
            if(SuffixArrayS1[i-tmp+1] < SuffixArrayS1[l]) {
                l = i - tmp + 1;
                r = i + p1[i+1];
            }
        }
    }
    if(curlen == 0) {
        cout << -1 << '\n';
        return;
    }
    string ans1, ans2;
    ans1.resize(curlen);
    int i, j;
    i = 0;
    j = curlen  - 1;
    while(l <= r) {
        ans1[i] = ans1[j] = s1[l];
        l++;
        i++;
        j--;
    }
    l = r = -1;
    curlen = 0;
    for (int i=0; i<m; i++) {
        int tmp = 0, p = 0;
        if (i > 0)
            p = p2[i-1];
        if(fd[n+i+1] != -1)
            tmp = max(tmp, GetLCP(iSA[n+i+1], iSA[fd[n+i+1]], len));
        if(bd[n+i+1] != -1)
        tmp = max(tmp, GetLCP(iSA[n+i+1], iSA[bd[n+i+1]], len));
        if((tmp > 0) && (curlen < tmp*2 + p)) {
            l = i-p;
            r = i+tmp-1;
            curlen = tmp*2 + p;
        } else if((tmp > 0) && (curlen == tmp*2 + p)) {
            if(SuffixArrayS2[i+tmp-1] < SuffixArrayS2[r]) {
                l = i-p;
                r = i+tmp-1;
            }
        }
    }

    ans2.resize(curlen);
    i = 0;
    j = curlen - 1;

    while(l <= r) {
        ans2[i] = ans2[j] = s2[r];
        r--;
        i++;
        j--;
    }

    if(ans1.length() != ans2.length()) {
        if(ans1.length() < ans2.length())
            cout << ans2 << '\n';
        else
            cout << ans1 << '\n';
    } else if(ans1 < ans2)
        cout << ans1 << '\n';
    else
        cout << ans2 << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        memset(p1, 0, sizeof(p1));
        memset(p2, 0, sizeof(p2));
        memset(iSA, 0, sizeof(iSA));
        memset(SA, 0, sizeof(SA));
        memset(fd, 0, sizeof(fd));
        memset(bd, 0, sizeof(bd));
        memset(cnt, 0, sizeof(cnt));
        memset(next_gen, 0, sizeof(next_gen));
        memset(lcp, 0, sizeof(lcp));
        memset(LCP, 0, sizeof(LCP));
        memset(SuffixArrayS1, 0, sizeof(SuffixArrayS1));
        memset(SuffixArrayS2, 0, sizeof(SuffixArrayS2));
        memset(bh, 0, sizeof(bh));
        memset(b2h, 0, sizeof(b2h));
        n = m = 0;
        s1 = s2 = Concat = s = "";
        ResetSuffTree();
        len = num = suff = 0;
        cin >> s1 >> s2;
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
