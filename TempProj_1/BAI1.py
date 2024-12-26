def Solve(arr):
    # Tinh tong n so
    sum_of_int = sum(arr)
    print("Tổng các số đã nhập là", sum_of_int)
    # Tao mang chi gom cac so chan trong n so dc nhap
    EvNum = [num for num in arr 
                    if num % 2 == 0]
    print("Danh sách các số chẵn là", EvNum)

A = [int(x) for x in input().split(', ')]
Solve(A)
