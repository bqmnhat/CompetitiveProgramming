#include <iostream>
#include <bits/stdc++.h>
#define MaxSN 101870000
#define MaxP 10000000
using namespace std;
typedef pair<int, int> pii;
bool Sieve[MaxSN+1];
int p[MaxP+1], cntBit[MaxP+1], cntBitOne[MaxP+1], pl = 0;
vector<pii> Q;

pii CountBits(int val) {
    pii ans = pii(0, 0);
    while (val > 0) {
        ans.first++;
        if (val&1)
            ans.second++;
        val >>= 1;
    }
    return ans;
}

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int i=2; i*i<=MaxSN; i++) {
        if (!Sieve[i]) {
            for (int j=i; i*j<=MaxSN; j++)
                Sieve[i*j] = true;
        }
    }
    for (int i=2; i<=MaxSN; i++) {
        if (!Sieve[i]) {
            pl++;
            p[pl] = i;
        }
    }
}

void MakeCntBitsAndOnes() {
    for (int i=1; i<=pl; i++) {
        pii tmp = CountBits(p[i]);
        cntBit[i] = cntBit[i-1] + tmp.first;
        cntBitOne[i] = cntBitOne[i-1] + tmp.second;
    }
}

int main()
{
    MakeSieve();
    MakeCntBitsAndOnes();
    return 0;
}
