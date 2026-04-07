class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;

        int actSum = 0;

        for (auto s: nums){
            actSum += s;
        }

        return expectedSum-actSum;
    }
};
