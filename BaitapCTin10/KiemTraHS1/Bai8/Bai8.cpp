#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int H[100000];
int Size = -1;

int LeftChild(int i) {
    return ((2 * i) + 1);
}

int RightChild(int i) {
    return ((2 * i) + 2);
}

int Parent(int i) {
    return (i - 1)/2;
}

void ShiftUp(int i) {
    while (i > 0 && H[Parent(i)] < H[i]) {
        swap(H[Parent(i)], H[i]);
        i = Parent(i);
    }
}

void ShiftDown(int i) {
    int MaxI = i, l = LeftChild(i);
    if (l <= Size && H[l] > H[MaxI]) {
        MaxI = l;
    }
    int r = RightChild(i);
    if (r <= Size && H[r] > H[MaxI]) {
        MaxI = r;
    }
    if (i != MaxI) {
        swap(H[i], H[MaxI]);
        ShiftDown(MaxI);
    }
}

void Insert(int p) {
    Size++;
    H[Size] = p;
    ShiftUp(Size);
}

int ExtractMax() {
    int ans = H[0];
    H[0] = H[Size];
    Size--;
    ShiftDown(0);
    return ans;
}

void ChangePriority(int i, int p) {
    int PrevP = H[i];
    H[i] = p;
    if (p > PrevP)
        ShiftUp(i);
    else
        ShiftDown(i);
}

int GetMax() {
    return H[0];
}

void Remove(int i) {
    H[i] = GetMax() + 1;
    ShiftUp(i);
    ExtractMax();
}

int main() {
    cout << "Chuc Co doc code vui ve";
    return 0;
}
