class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long prod = 1;
        vector<int> ans(nums.size());
        vector<int> zero_index;

        // 1) Find zeros and compute product of all non-zero elements
        for (int i = 0; i < (int)nums.size(); ++i) {
            if (nums[i] == 0) {
                zero_index.push_back(i);
            } else {
                prod *= nums[i];
            }
        }

        // 2) Build answer based on how many zeros we saw
        if (zero_index.size() > 1) {
            // More than one zero: everything is zero
            fill(ans.begin(), ans.end(), 0);
        } else if (zero_index.size() == 1) {
            // Exactly one zero: only the zero position gets 'prod', others are
            // zero
            int zi = zero_index[0];
            fill(ans.begin(), ans.end(), 0);
            // ans[zi] = static_cast<int>(prod);
            ans[zi] = prod;
        } else {
            // No zeros: each position is total product divided by nums[i]
            for (int i = 0; i < (int)nums.size(); ++i) {
                ans[i] = (int)(prod / nums[i]);
            }
        }

        return ans;
    }
};
