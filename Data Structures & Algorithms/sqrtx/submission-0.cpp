class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int left = 1, right = x / 2;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Check if mid*mid <= x using division to avoid overflow
            if (mid <= x / mid) {
                ans = mid;     // mid is a potential answer
                left = mid + 1; // Try to find a larger value
            } else {
                right = mid - 1; // mid is too large
            }
        }
        
        return ans;
    }
};