//3-1-2026 3
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>seen(256,-1);
        int left =0;
        int right=0;
        int longest =0;
        for(int i=0;i<s.size();i++){
            unsigned char c = s[i];
            if(seen[c]>=0){
                longest =std::max(longest, right-left);
                left= std::max(left,seen[c]+1);   
            }
            seen[c]=i;
            right++;
        }
        longest =std::max(longest, right-left);
        return longest;
    }
};