//5-1-2026 2
//finished on 6th
//really hate sliding window
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> window(256,0);
        vector<int> substring(256,0);
        if (t.size()>s.size()){
            return "";
        }
        int distinctSubstring =0;
        int distinctWindow =0;
        for(auto c: t){
            unsigned char uc = c;
            if(substring[uc] == 0) distinctSubstring++;
            substring[uc]++;
        }
        int left =0;
        int bestl=0;
        int bestr =INT_MAX;
        for(int right =0; right <s.size();right++){
            unsigned char c = s[right];
            window[c]++;
            if(substring[c]>0 && window[c]==substring[c]){
                distinctWindow++;
            }
            while(distinctSubstring==distinctWindow){
                if ((bestr - bestl > right -left)){
                        bestr= right;
                        bestl=left;
                    }
                unsigned char l = s[left];
                window[l]--;
                left++;
                if (window[l]<substring[l]){
                    distinctWindow--;
                }
                
            }
        }
        return bestr == INT_MAX ? "" : s.substr(bestl, bestr - bestl + 1);

    }
};