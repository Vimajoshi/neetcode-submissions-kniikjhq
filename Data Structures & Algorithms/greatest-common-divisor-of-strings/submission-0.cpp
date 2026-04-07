#include <string>
#include <numeric> // For std::gcd

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // Check if concatenating in different orders yields the same string
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        
        // Calculate GCD of the lengths
        int gcdLength = std::gcd(str1.length(), str2.length());
        
        // Return the substring of the calculated length
        return str1.substr(0, gcdLength);
    }
};