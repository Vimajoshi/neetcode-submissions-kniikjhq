class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;

        for(int i=0; i<nums.size(); i++){
            int cmp = target - nums[i];

            if(umap.find(cmp) != umap.end()){
                return {umap[cmp],i};
            }

            umap[nums[i]] = i;
        }

        return {-1,-1};
    }
};
