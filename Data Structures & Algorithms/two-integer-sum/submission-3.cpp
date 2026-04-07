class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> umap; // store (value,index) pair

        // vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int comp = target - nums[i];

            if(umap.find(comp) != umap.end()){
                return {umap[comp], i};
            }

            umap[nums[i]] = i;
        }
        return {-1,-1};
    }
};
