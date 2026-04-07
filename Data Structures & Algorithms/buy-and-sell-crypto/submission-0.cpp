class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_prc = INT_MAX;
        int max_pro = 0;

        for(int it : prices){
            if(it < min_prc){
                min_prc = it;
            }
            else if(it - min_prc > max_pro){
                max_pro = it - min_prc;
            }
        }
        return max_pro;
    }
};
