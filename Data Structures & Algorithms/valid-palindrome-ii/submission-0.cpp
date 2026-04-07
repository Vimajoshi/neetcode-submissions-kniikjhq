class Solution {
public:
    bool isPal(string s, int st, int en){

        while(st <= en){
            if(s[st] != s[en])
                return false;
            
            st++; en--;
        }
        return true;
    }
    bool validPalindrome(string s) {

        int i = 0;
        int j = s.size()-1;

        while(i<=j){
            if(s[i] == s[j]){
                i++;
                j--;
            }else{
                return isPal(s, i+1, j) or isPal(s, i, j-1);
            }
        }
        return true;
    }
};