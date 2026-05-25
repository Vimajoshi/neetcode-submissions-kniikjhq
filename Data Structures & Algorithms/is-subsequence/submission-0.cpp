class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // Pointer for s
        int j = 0; // Pointer for t
        
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++; // Move s pointer if characters match
            }
            j++; // Always move t pointer
        }
        
        return i == s.length();
    }
};