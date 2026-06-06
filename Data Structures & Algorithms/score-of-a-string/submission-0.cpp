class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        
        // Iterate through the string, stopping at the second-to-last character
        for (size_t i = 0; i < s.length() - 1; ++i) {
            // Calculate the absolute difference between adjacent characters
            score += std::abs(s[i] - s[i + 1]);
        }
        
        return score;
    }
};