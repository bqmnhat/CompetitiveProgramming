#include <iostream>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
Giai pt nghiem nguyen khong am 2x + y = c (c <= 1e6)
Tim 1 nghiem
- Buoc 1: Nhap c
- Buoc 2: x = 1
- Buoc 3: c - 2

Giai pt nghiem nguyen khong am 2x + y = c (c <= 1e6)
Dem so bo nghiem x,y:
Vd:
c = 6
2x + y = 6
- x = 0 && y = 6
- x = 1 && y = 4
- x = 2 && y = 2
- x = 3 && y = 0

- Gia su y = 0 => 2x = c
y = 1 => 2x = c-1
.
.
.

- x && y >= 0 (1)
- x <= c/2 && y <= c (2)
- if co x thoa (1) && (2) => tinh dc y (3)
Tu (1) va (2)
- Nhat cm: 0<=x<=c/2; 0<=y<=c; (4)
- Cm dc rang chay x tu 0 => c/2 r tinh y se tim dc tat ca bo nghiem
#######################
Giai pt nghiem nguyen khong am ax + by = c (c <= 1e6)
Dem so bo nghiem x,y:
- x && y >= 0 (1)
- x <= c/a && y <= c/b (2)
- if co x thi tinh dc y
Tu (1) va (2)
- 0 <= x <= c/a; 0<=y<=c/b
- Cm dc rang chay x tu 0 => c/a r tinh y se tim dc tat ca bo nghiem

O(MaxN) (MaxN la so lan loop trong TH te nhat):
    - Neu MaxN <= 4e7: Co the chay duoi 1s
    - Neu MaxN <= 1e6: Chac chan duoi 1s

Goi a,b la uoc cua x (a <= b)
a*b = x
a <= b
a*a <= a*b <= x
=> a<=sqrt(x)

unsigned long long fib[51];
fib[1] = 1;
fib[2] = 1;
for (int i=3; i<=n; i++) {
    fib[i] = fib[i-2] + fib[i-1];
}
cout << fib[n];
