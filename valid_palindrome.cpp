//30-12-2025 2
class Solution {
public:
    bool isPalindrome(string s) {
        int left =0;
        int right = s.size()-1;
        while(left <right){
            while(left < right && !std::isalnum(static_cast<unsigned char>(s.at(left)))){
                left++;
            }
            while(left < right && !std::isalnum(static_cast<unsigned char>(s.at(right)))){
                right--;
            }
            if (std::tolower(static_cast<unsigned char>(s.at(left)))!=std::tolower(static_cast<unsigned char>(s.at(right)))){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};