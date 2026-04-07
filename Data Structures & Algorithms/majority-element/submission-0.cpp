class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        int n = nums.size()/2;

        for(auto i: nums){
            umap[i]++;
        }

        for(auto i: umap){
            if(i.second > n){
                return i.first;
            }
        }

        return -1;
    }
};