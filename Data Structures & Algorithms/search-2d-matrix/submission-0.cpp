class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if (matrix.empty() || matrix[0].empty()) return false;
    int m = matrix.size();
    int n = matrix[0].size();

    int lo = 0;
    int hi = m * n - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;        // avoid overflow
        int r = mid / n;                     // row index in 2D
        int c = mid % n;                     // column index in 2D
        int val = matrix[r][c];

        if (val == target) return true;
        if (val < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return false;
    }
};
