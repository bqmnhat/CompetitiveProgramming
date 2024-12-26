#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> nums1, nums2;

double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size(), m = nums2.size(), mid, FromNums2;
        if (m == 0) {
            if (n%2 == 0)
                return ((double)nums1[n/2 - 1] + (double)nums1[n/2])/2.0;
            else
                return (nums1[(n+1)/2 - 1]);
        }
        if (n == 0) {
            if (m%2 == 0)
                return ((double)nums2[m/2 - 1] + (double)nums2[m/2])/2.0;
            else
                return (nums2[(m+1)/2 - 1]);
        }
        double med = 0;
        int MedIdInMergedArray = ((n + m + 1) >> 1);
        int lo = 0, hi = n;
        while (lo <= hi) {
            mid = ((lo + hi) >> 1); // mid == FromNums1
            FromNums2 = MedIdInMergedArray - mid;
            if (FromNums2 < 0) {
                hi = mid - 1;
                continue;
            }
            if ((mid < n) && (FromNums2-1 >= 0) && (nums1[mid] < nums2[FromNums2-1]))
                lo = mid + 1;
            else if (((FromNums2 < m) && (mid-1 >= 0) && (nums1[mid-1] > nums2[FromNums2])))
                hi = mid - 1;
            else if ((mid == 0) && (FromNums2 - 1 >= 0)) {
                med = nums2[FromNums2-1];
                break;
            }
            else if ((FromNums2==0) && (mid - 1 >= 0)) {
                med = nums1[mid-1];
                break;
            }
            else {
                med = max(nums1[mid-1], nums2[FromNums2-1]);
                break;
            }
        }
        if ((n+m)%2 == 1)
            return med;
        if (mid == n)
            return ((med + (double)nums2[FromNums2])/2.0);
        if (FromNums2 == m)
            return ((med + (double)nums1[mid])/2.0);
        return ((med + (double)min(nums1[mid], nums2[FromNums2]))/2.0);
    }

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int val;
        cin >> val;
        nums1.push_back(val);
    }
    for (int i=1; i<=m; i++) {
        int val;
        cin >> val;
        nums2.push_back(val);
    }
    cout << findMedianSortedArrays(nums1, nums2);
    return 0;
}
