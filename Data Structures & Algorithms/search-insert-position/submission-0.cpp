class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int r = nums.size()-1;
        int l = 0;


        while(r>=l){
            int m = (r+l)/2;

            if(target == nums[m]){
                return m;
            }else if(target > nums[m]){
                l = m+1;
            }else{
                r  = m-1;
            }
        }

        return l;

    }
};