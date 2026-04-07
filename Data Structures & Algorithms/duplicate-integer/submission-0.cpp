class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> umap;

        for(auto i: nums){
            umap[i]++;
        }

        for(auto i: umap){
            if(i.second > 1){
                return true;
            }
        }
        return false;
    }
};