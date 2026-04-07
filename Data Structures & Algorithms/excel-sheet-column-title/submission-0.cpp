#include <string>
#include <algorithm>

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        
        while (columnNumber > 0) {
            columnNumber--; // Adjust to 0-indexed system
            int remainder = columnNumber % 26;
            result += (char)('A' + remainder);
            columnNumber /= 26;
        }
        
        // Since we appended chars, the order is reversed (Least Significant Digit first)
        reverse(result.begin(), result.end());
        return result;
    }
};