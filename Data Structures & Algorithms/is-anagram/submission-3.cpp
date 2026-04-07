class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        vector<int> arr(26,0);


        for(int i=0; i<s.size(); i++){
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }

        for(auto i:arr){
            if(i!=0){
                return false;
            }
        }
        return true;
    }
};
