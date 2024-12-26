def Solve(arr):
    # Nhap so nguyen k
    k = int(input("k="))
    # Dem so phan tu trong A co gia tri bang k
    cnt_k = arr.count(k)
    print("Số lượng số", k, "trong danh sách:", cnt_k)
    # Xoa tat ca cac phan tu co gia tri bang k trong danh sach A
    arr = [element for element in A if element != k]
    print(f"Danh sách sau khi xóa số {k}: {arr}")

A = list(map(int, input().split(', ')))
Solve(A)