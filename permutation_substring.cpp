//5-1-2026 1
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        vector<int> s1freq(26,0);
      
        for (auto c :s1){
            s1freq[c-'a']++;
        }
        int left =0;
        for(int right =0;right< s2.size();right++ ){
            freq[s2[right]-'a']++;

            if(right - left + 1 > s1.size()){
                freq[s2[left]-'a']--;
                left++;       
            }
            if(freq == s1freq){
                return true;
            }  
        }
        return false;
    }
};