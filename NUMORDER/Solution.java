package com.seven.dollar.telegramebot.util;

public class Solution {
    class Range {
        int countAll;
        int countEqual;
    }

    private int n;
    private int m;

    public Solution(int row, int col) {
        n = row;
        m = col;
    }

    /**
     * Count the number of value that out side the matrix
     * @param flex
     * @param hard
     * @return
     */
    public Range count(int flex, int hard, int max) {
        Range result = new Range();
        long value = flex * flex + hard * hard;
        int r = flex + 1;
        int c = (int) Math.sqrt(value - r*r);

        while (r <= max && c > 0) {
            result.countAll += c;
            if (r*r + c*c == value) {
                result.countEqual++;
            }
            r++;
            c = (int) Math.sqrt(value - r*r);
        }

        return result;
    }

    /**
     * Find the index of this cell in the final result
     * @param row
     * @param col
     * @return
     */
    public Range findIndex(int row, int col) {
        Range result = new Range();
        Range right = count(row, col, n); // in the right side
        Range bottom = count(col, row, m); // in the bottom side

        result.countAll = row * col; // the value now is the maximum in the matrix [1..row, 1..col]
        // re-calculate the index by all the cell that out size of the matrix and less than the value
        result.countAll += right.countAll;
        result.countEqual += right.countEqual;
        result.countAll += bottom.countAll;
        result.countEqual += bottom.countEqual;

        return result;
    }

    public long solution(int idx) {
        int minCol = 1, maxCol = m;
        int minRow = 1, maxRow = n;

        // firstly, find the column that contains the result
        while (minCol < maxCol) {
            int middle = (minCol + maxCol) / 2;
            Range maxColIdx = findIndex(n, middle);
            Range nextColMinIdx = findIndex(1, middle+1);
            int fromIdx = maxColIdx.countAll - maxColIdx.countEqual;
            int toIdx = maxColIdx.countAll;

            if (idx >= fromIdx && idx <= toIdx) {
                return middle * middle + n * n;
            }
            if (toIdx < idx || nextColMinIdx.countAll <= idx) {
                minCol = middle + 1;
            } else if (fromIdx > idx) {
                maxCol = middle - 1;
            }
        }
        // then, find the row of the result
        while (minRow < maxRow) {
            int middle = (minRow + maxRow) / 2;
            Range index = findIndex(middle, minCol);
            int fromIdx = index.countAll - index.countEqual;
            int toIdx = index.countAll;

            if (toIdx < idx) {
                minRow = middle + 1;
            } else if (fromIdx > idx) {
                maxRow = middle - 1;
            } else {
                return middle * middle + minCol * minCol;
            }
        }

        return minRow * minRow + minCol * minCol;
    }

    public static void main(String[] args) {
        Solution s = new Solution(3, 5);
        for (int i = 1; i <= 15; ++i) {
            System.out.println(s.solution(i) + " ");
        }
        // performance test
        Solution s1 = new Solution(31000, 31000);
        long start = System.currentTimeMillis();
        System.out.println(s1.solution(686868686));
        long end = System.currentTimeMillis();
        System.out.println("Run time: " + (end - start) + " ms.");
    }
}
