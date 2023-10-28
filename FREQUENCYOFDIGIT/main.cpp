#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int t, n, k, a[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int CountDigitK(int num, int k) { // dem so chu so loai "k" xuat hien trong bieu dien thap phan cua so "num"
    int cnt = 0;
    while (num > 0) {
        int currentDigit = num%10;
        num /= 10;
        if (currentDigit == k)
            cnt++;
    }
    return cnt;
}
// Minh viet ham "CountDigitK" vi nhung thao tac duoc thuc hien trong ham nay dc lap di lap lai nhieu lan
// va no phuc vu cho mot muc dich nhat dinh: dem so lan chu so "k" xuat hien trong "num"

int SolForTestcase(int k) { // Ham nay giai 1 testcase
    int res = 0;
    for (int i=1; i<=n; i++)
        res += CountDigitK(a[i], k);
    return res;
}

void SolveAllTestcase() {
    //Ham nay se giai cho tat ca t testcase
    //Phan nay em tu code nhe ;)
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
