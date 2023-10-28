#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int cnt[100001], p[100001], c[100001];

vector<int> BuildSuffixArray(string s) {
    int n = s.size();
    const int alphabet = 256;
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
}

int main()
{
    vector<int> a = BuildSuffixArray("dabbb");
    return 0;
}
